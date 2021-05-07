#pragma once
#include <vector>
#include <string>
using namespace std;
class _8字符串转换整数
{
	class Solution {
	public:
		int myAtoi(string str) {
			//使用向量来保存自string转换int后每一位上的数字
			vector<int> vec;
			//symbol判断是否是负数，false就是负数，默认为正
			bool symbol = true;
			//由于超过INT_MAX或者INT_MIN要返回INT_MAX或者INT_MIN，因此使用longlong来比较大小
			long long result = 0;
			//找到第一个非空字符的下标，存到neof
			int neof;
			//找非空字符
			for (int i = 0; i < str.length(); ++i)
			{
				if (str[i] == ' ')
					continue;
				else
				{
					neof = i;
					break;
				}
			}
			//判断第一个非空字符是否有效，无效直接返回，顺便判断值的正负性
			if ((str[neof] != '-' && str[neof] != '+') && (str[neof] < '0' || str[neof] > '9'))
				return 0;
			else if (str[neof] == '-')
			{
				symbol = false;
				neof++;
			}
			else if (str[neof] == '+')
			{
				symbol = true;
				neof++;
			}
			bool temp = true;
			//首先找到第一个有效数字，例如-00000000000001等于-1，因此要将0舍弃，从1开始记录
			//然后做一个标记，防止后面的有效0也被舍弃了
			//接着将数字存到向量中，由于ascii中数字-48就是实际值，因此有了 str[neof]-48 的操作
			for (; neof < str.length(); neof++)
			{
				if (temp)
				{
					if (str[neof] != '0')
						temp = false;
					if (temp)
						continue;
				}
				if (str[neof] >= '0' && str[neof] <= '9')
					vec.push_back(str[neof] - 48);
				else
					break;
			}
			//判断向量是否为空，空就直接返回
			if (vec.begin() == vec.end())
				return 0;
			auto iter = vec.end();
			iter--;
			long long c = 1;
			//从个位数依次加到末位
			for (iter; iter != vec.begin(); iter--)
			{
				result += *iter * c;
				c *= 10;
				if (c > INT_MAX)
				{
					return symbol ? INT_MAX : INT_MIN;
				}
			}
			//判断正负以及是否越界
			result += vec[0] * c;
			if (!symbol)
				result = 0 - result;
			if (result > INT_MAX)
				return INT_MAX;
			if (result < INT_MIN)
				return INT_MIN;
			return result;
		}
	};
};

