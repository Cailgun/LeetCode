#pragma once
#include <vector>
#include <algorithm>
class _16最接近的三数之和
{
	class Solution {
	public:
		unsigned int FindClosestNum(std::vector<int>& nums, unsigned int miniIndex, int target)
		{
			unsigned int length = nums.size();
			unsigned int maxIndex = length - 1;
			if (miniIndex == maxIndex)
			{
				return miniIndex;
			}

			int midIndex = 0;
			while (maxIndex > miniIndex)
			{
				midIndex = (maxIndex + miniIndex) / 2;
				if (target > nums[midIndex])
				{
					miniIndex = midIndex + 1;
					continue;
				}
				else if (target < nums[midIndex])
				{
					maxIndex = midIndex - 1;
					continue;
				}
				else if (target == nums[midIndex])
				{
					return midIndex;
				}
			}
			unsigned int dif1 = 9999999;
			unsigned int dif2 = 9999999;
			unsigned int dif3 = 9999999;
			if ((midIndex + 1) < length)
			{
				dif1 = abs(target - nums[midIndex + 1]);
			}
			if ((midIndex - 1) > 0 && (midIndex - 1) > miniIndex)
			{
				dif2 = abs(target - nums[midIndex - 1]);
			}
			dif3 = abs(target - nums[midIndex]);
			return dif1 < dif2 ? (dif1 < dif3 ? midIndex + 1 : midIndex) : (dif2 < dif3 ? midIndex - 1 : midIndex);

		}

		int threeSumClosest(std::vector<int>& nums, int target) {
			unsigned int length = nums.size();
			sort(nums.begin(), nums.end());

			unsigned int maxNum = 9999999;
			int ret = 0;
			for (int i = 0; i < length; ++i)
			{
				for (int j = i + 1; j < length; ++j)
				{
					if (j == length - 1)
						break;
					int res = nums[i] + nums[j];
					unsigned int index = FindClosestNum(nums, j + 1, target - res);
					if (abs(target - res - nums[index]) < maxNum)
					{
						maxNum = abs(target - res - nums[index]);
						ret = res + nums[index];
					}
				}
			}
			return ret;
		}
	};
};

