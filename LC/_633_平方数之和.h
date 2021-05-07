#pragma once
#include <vector>
class Solution {
public:
	long long getBinaryNum(long long left, long long right)
	{
		return (left + right) / 2;
	}
	bool judgeSquareSum(long long c) {
		if (c < 0)
		{
			return false;
		}

		long long root = sqrt(c);
		if ((double)root == sqrt(c))
		{
			return true;
		}

		for (long long i = 0; i <= root; ++i)
		{
			long long left = i;
			long long right = root;
			long long mid = (i + root) / 2;
			do
			{
				long long sum = i * i + mid * mid;
				if (sum > c)
				{
					right = mid - 1;
					mid = getBinaryNum(left, right);
				}
				else if (sum < c)
				{
					left = mid + 1;
					mid = getBinaryNum(left, right);
				}
				else
				{
					return true;
				}
			} while (left <= right);
		}
		return false;
	}
};