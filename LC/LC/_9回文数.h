#pragma once
#include <vector>
using namespace std;
class _9回文数
{
	class Solution {
	public:
		bool isPalindrome(int x) {
			//负数肯定不是回文数
			if (x < 0)
				return false;
			//小于10的正整数一定是回文数 
			if (x < 10)
				return true;
			//然后用向量将数的每一位存下来，再挨着挨着比较相应位置的数是否相等
			vector<long long> vec;
			long long mod = 1;
			while (x != 0)
			{
				long long temp = (x % (mod * 10)) / mod;
				vec.push_back(temp);
				x = x - temp * mod;
				mod *= 10;
			}
			//用头迭代器和尾迭代器挨着比较，由于尾部是最后一个元素的后一位，因此要先--
			auto iterbegin = vec.begin();
			auto iterend = vec.end();
			iterend--;
			while (iterbegin != iterend)
			{
				if (*iterbegin != *iterend)
					return false;
				else
				{
					iterbegin++;
					//如果两个迭代器相等了，就说明所有的数都比较完了，可以跳出循环
					if (iterend == iterbegin)
						break;
					iterend--;
				}
			}
			return true;
		}
	};
};

