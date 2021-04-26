#pragma once
#include <vector>
class _456_132模0式
{
public:
	class Solution {
	public:
		enum class RefreshType
		{
			AtBottom,
			Other
		};

		std::vector<int> interval;	//第奇数个为数轴左，第偶数个为数轴右，开区间

		bool check(int num)
		{
			size_t size = interval.size() / 2;
			for (size_t i = 0; i < size; ++i)
			{
				if (num > interval[i * 2] && num < interval[i * 2 + 1])
				{
					return true;
				}
			}
			return false;
		}

		int findNextPair(std::vector<int>& nums, int currentPos, bool& ret)
		{
			int minimum = nums[currentPos];
			int maximum = nums[currentPos++];
			bool success = false;
			size_t size = nums.size();
			for (; currentPos < size; ++currentPos)
			{
				if (nums[currentPos] < minimum)
				{
					minimum = nums[currentPos];
				}
				else
				{
					maximum = nums[currentPos];
					ret = check(maximum);
					success = true;
					break;
				}
			}
			if (success)
			{
				interval.push_back(minimum);
				interval.push_back(maximum);
			}
			return currentPos + 1;
		}

		RefreshType refreshInterval(int num)
		{
			RefreshType ret = RefreshType::AtBottom;

			size_t size = interval.size();
			for (size_t i = 0; i < size; ++i)
			{
				if (!(i % 2))
				{
					if (interval[i] <= num)
						ret = RefreshType::Other;
				}
				else if (interval[i] < num)
				{
					interval[i] = num;
				}
			}
			return ret;
		}

		void compressionInterval()
		{
			//将多个区间的重复部分压成一个区间
		}

		bool find132pattern(std::vector<int>& nums)
		{
			size_t size = nums.size();
			if (size < 3)
			{
				return false;
			}
			bool b;
			int currentPos = findNextPair(nums, 0, b);
			for (; currentPos < size; ++currentPos)
			{
				if (check(nums[currentPos]))
				{
					return true;
				}
				if (refreshInterval(nums[currentPos]) == RefreshType::AtBottom)
				{
					bool ret = false;
					currentPos = findNextPair(nums, currentPos, ret);
					if (ret)
					{
						return true;
					}
					--currentPos;
				}
				compressionInterval();
			}
			return false;
		}
	};
};

