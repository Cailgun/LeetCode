#pragma once
#include <string>
class _13罗马数字转整数
{
	class Solution {
	public:
		static int romanToInt(std::string s) {
			int ret = 0;
			char last = ' ';
			for (int iter : s)
			{
				if (iter == 'M')
				{
					if (last == 'C')
					{
						ret += 800;
					}
					else
					{
						ret += 1000;
					}
				}
				else if (iter == 'D')
				{
					if (last == 'C')
					{
						ret += 300;
					}
					else
					{
						ret += 500;
					}
				}
				else if (iter == 'C')
				{
					if (last == 'X')
					{
						ret += 80;
					}
					else
					{
						ret += 100;
					}
				}
				else if (iter == 'L')
				{
					if (last == 'X')
					{
						ret += 30;
					}
					else
					{
						ret += 50;
					}
				}
				else if (iter == 'X')
				{
					if (last == 'I')
					{
						ret += 8;
					}
					else
					{
						ret += 10;
					}
				}
				else if (iter == 'V')
				{
					if (last == 'I')
					{
						ret += 3;
					}
					else
					{
						ret += 5;
					}
				}
				else
				{
					ret += 1;
				}
				last = iter;
			}
			return ret;
		}
	};
};

