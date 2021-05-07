#pragma once
class _1486_数组异或操作
{
	class Solution {
	public:
		int xorOperation(int n, int start) {
			if (n == 1)
			{
				return start;
			}
			int ret = start;
			for (int i = 1; i < n; ++i)
			{
				ret ^= start + i * 2;
			}
			return ret;
		}
	};
};

