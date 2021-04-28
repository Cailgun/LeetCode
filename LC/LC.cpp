#include <iostream>
#include <vector>
#include <io.h>
#include <functional>
using namespace std;

int load(std::vector<int>& weights, int capacity)
{
	int count = 0;
	int day = 1;
	for (auto iter : weights)
	{
		if (count + iter > capacity)
		{
			count = 0;
			day++;
		}
		count += iter;
	}
	return day;
}

int findCapacity(int left, int right, std::vector<int>& weights, int D)
{
	if (left == right)
	{
		return left;
	}
	if (abs(left - right) == 1)
	{
		return (load(weights, left) == D) ? left : right;
	}

	int mid = (left + right) / 2;
	int currentD = load(weights, mid);
	if (currentD > D)
	{
		return findCapacity(mid, right, weights, D);
	}
	else if (currentD < D)
	{
		return findCapacity(left, mid, weights, D);
	}

	int lastD = load(weights, mid - 1);

	if (lastD == D)
	{
		return findCapacity(left, mid, weights, D);
	}
	else
	{
		return mid;
	}
}

int shipWithinDays(std::vector<int>& weights, int D) {
	size_t size = weights.size();
	if (size == 0)
	{
		return 0;
	}
	int capacity = 1;
	for (auto iter : weights)
	{
		if (iter > capacity)
			capacity = iter;
	}
	int lastCapacity = capacity;
	while (true)
	{
		int currentD = load(weights, capacity);
		if (currentD <= D)
		{
			return findCapacity(lastCapacity, capacity, weights, D);
		}
		lastCapacity = capacity;
		capacity *= 2;
	}
}

int main()
{
	vector<int> v({10, 50, 100, 100, 50, 100, 100, 100});
	int i = shipWithinDays(v, 5);

	return 0;
}