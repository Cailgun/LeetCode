#pragma once
#include <string>
#include <vector>
class _20ÓÐÐ§µÄÀ¨ºÅ
{
	class Solution {
	public:
		class stack
		{
		public:
			char cache[10000];
			int size = 0;
			stack() :size(0) {}
			void push(char ch)
			{
				cache[size] = ch;
				size++;
			}
			void pop()
			{
				size--;
			}
		};

		bool isValid(std::string s) {
			std::vector<char> vec;
			stack st;
			for (auto iter : s)
			{
				if ((iter == '}' || iter == ')' || iter == ']') && st.size == 0)
				{
					return false;
				}
				if (iter == '{' || iter == '(' || iter == '[')
				{
					st.push(iter);
				}
				else if (iter == '}' && st.cache[st.size - 1] == '{')
				{
					st.pop();
				}
				else if (iter == ']' && st.cache[st.size - 1] == '[')
				{
					st.pop();
				}
				else if (iter == ')' && st.cache[st.size - 1] == '(')
				{
					st.pop();
				}
				else
					return false;
			}
			return st.size == 0;
		}
	};
};

