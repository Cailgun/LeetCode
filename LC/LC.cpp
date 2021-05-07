#include <iostream>
#include <vector>
#include <io.h>
#include <functional>
using namespace std;

int getBinaryNum(int left, int right)
{
	return (left + right) / 2;
}
bool judgeSquareSum(int c) {
	if (c < 0)
	{
		return false;
	}

	int root = sqrt(c);
	if ((double)root == sqrt(c))
	{
		return true;
	}

	for (int i = 0; i <= root; ++i)
	{
		int left = i;
		int right = root;
		int mid = (i + root) / 2;
		do
		{
			int sum = i * i + mid * mid;
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

int main()
{
	judgeSquareSum(173);
	return 0;
}