#pragma once
#include <vector>
#include <algorithm>
class _18四数之和
{
	class Solution {
	public:
		std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
			auto size = nums.size();
			std::sort(nums.begin(), nums.end());
			std::vector<std::vector<int>> ret;
			if (size < 4)
			{
				return ret;
			}


			for (int i = 0; i < size; ++i)
			{
				for (int j = i + 1; j < size; ++j)
				{
					for (int k = j + 1; k < size; ++k)
					{
						for (int l = k + 1; l < size; ++l)
						{
							if (nums[i] + nums[j] + nums[k] + nums[l] == target)
							{
								ret.push_back({ nums[i], nums[j], nums[k], nums[l] });
								break;
							}
						}
					}
				}
			}
			sort(ret.begin(), ret.end());
			ret.erase(unique(ret.begin(), ret.end()), ret.end());
			return ret;
		}
	};
};

