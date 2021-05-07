#pragma once
#include <vector>
#include <algorithm>
#include <map>
class _15三数之和
{
	class Solution {
	public:

		static std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
			sort(nums.begin(), nums.end());

			unsigned int length = nums.size();
			std::map<std::vector<int>, int> ret;
			std::vector<std::vector<int>> retVec;

			for (int i = 0; i < length; ++i)
			{
				if (nums[i] == 0 && i + 2 < length && nums[i + 1] == 0 && nums[i + 2] == 0)
				{
					ret[std::vector<int>({ 0,0,0 })] = 0;
					break;
				}
				else if (nums[i] > 0)
				{
					break;
				}
				for (int j = i + 1; j < length; ++j)
				{
					int res = nums[i] + nums[j];
					if (res + nums[length - 1] < 0)
					{
						continue;
					}
					else
					{
						auto iter = std::binary_search(nums.begin() + j + 1, nums.end(), -res);
						if (iter)
						{
							retVec.push_back({ nums[i], nums[j], -res });
						}
					}
				}
			}
			sort(retVec.begin(), retVec.end());
			retVec.erase(unique(retVec.begin(), retVec.end()), retVec.end());
			return retVec;
		}
	};
};

