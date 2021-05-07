#pragma once
#include <vector>
class _26删除有序数组中的重复项
{
	class Solution {
	public:
		int removeDuplicates(std::vector<int>& nums) {
			if (nums.size() == 0)
			{
				return 0;
			}
			int size = 0;
			for (int i = 0; i < nums.size(); ++i)
			{
				if (nums[size] == nums[i])
				{
					continue;
				}
				else
				{
					nums[++size] = nums[i];
				}
			}
			return size + 1;
		}
	};
};

