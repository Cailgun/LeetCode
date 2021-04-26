#pragma once
#include <vector>
using namespace std;

class NestedInteger {
public:
	NestedInteger() :state(false) {}
	NestedInteger(int i) :num(i), state(true) {}

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger()
	{
		return state;
	}

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const
	{
		if (state)
			return num;
		else
			return -1;
	}

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger>& getList() const
	{
		if (!state)
			return vec;
		else
			return vector<NestedInteger>();
	}
	vector<NestedInteger> vec;
	bool state;
	int num;
};

class NestedIterator {
public:
	NestedIterator(vector<NestedInteger>& nestedList)
	{
		_iter = nestedList.begin();
		_end = nestedList.end();
		_done = false;
		_allDone = false;
	}

	int next() {
		{
			if (_done)
			{
				_done = false;
				return n;
			}
		}
		int ret = 0;
		if (_iter == _end)
		{
			if (_iterStack.size())
			{
				_iter = _iterStack[_iterStack.size() - 1];
				_iterStack.pop_back();
				_end = _endStack[_endStack.size() - 1];
				_endStack.pop_back();
				return next();
			}
			else
			{
				_allDone = true;
				return -1;
			}
		}

		if (_iter->isInteger())
		{
			ret = _iter->getInteger();
			_iter++;
		}
		else
		{
			vector<NestedInteger> l = _iter->getList();
			_list.push_back(l);
			_iterStack.push_back(++_iter);
			_endStack.push_back(_end);

			_iter = _list[_list.size() - 1].begin();
			_end = _list[_list.size() - 1].end();
			return next();
		}

		return ret;
	}

	bool hasNext() {
		n = next();
		_done = !_allDone;
		return !_allDone;
	}

private:
	bool _done;
	bool _allDone;
	int n;
	vector<vector<NestedInteger>> _list;
	vector<NestedInteger>::iterator _iter;
	vector<NestedInteger>::iterator _end;
	vector<vector<NestedInteger>::iterator> _iterStack;
	vector<vector<NestedInteger>::iterator> _endStack;
};

