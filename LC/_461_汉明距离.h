#pragma once
class _461_��������
{
	class Solution {
	public:
		int hammingDistance(int x, int y) {
			auto result = x ^ y;
			int ret = 0;
			while (result != 0)
			{
				if (result % 2 == 1)
				{
					ret++;
				}
				result >>= 1;
			}
			return ret;
		}
	};
};

