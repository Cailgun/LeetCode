#pragma once
#include <vector>
class _27ÒÆ³ýÔªËØ
{
	class Solution
	{
	public:
		int removeElement(std::vector<int>& nums, int val)
		{
			auto size = nums.size();
			for (int i = 0; i < nums.size(); ++i)
			{
				if (i == size)
				{
					return size;
				}
				if (nums[i] == val)
				{
					std::swap(nums[i--], nums[size-- - 1]);
				}
			}
			return size;
		}
	};
};

