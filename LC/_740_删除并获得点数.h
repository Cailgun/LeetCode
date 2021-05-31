#pragma once
#include <vector>
#include <algorithm>
class _740_删除并获得点数
{
	class Solution {
	public:
		int deleteAndEarn(std::vector<int>& nums) {
			std::sort(nums.begin(), nums.end());
			std::vector<std::pair<int, int>> ary;
			int size = nums.size();
			if (size == 1)
			{
				return nums[0];
			}
			int last = nums[0];
			int cnt = 1;
			for (int i = 1; i < size; ++i)
			{
				if (nums[i] == last)
				{
					cnt++;
				}
				else
				{
					ary.push_back(std::pair<int, int>(last, cnt * last));
					last = nums[i];
					cnt = 1;
				}
				if (i == size - 1)
				{
					ary.push_back(std::pair<int, int>(last, cnt * last));
				}
			}

			auto compare = [&](std::pair<int, int> frt, std::pair<int, int> sec)
			{
				return frt.first < sec.first;
			};
			auto getContinuously = [&](std::vector<std::pair<int, int>> vec)
			{
				std::vector<std::pair<int, int>> ret;
				int size = vec.size();
				int start = 0;
				int end = 0;
				int current = vec[0].first;
				int temp = 0;
				for (int i = 0; i < size; ++i, ++temp)
				{
					if (vec[i].first == temp + current)
					{
						end = i;
					}
					else
					{
						ret.push_back(std::pair<int, int>(start, end));
						start = end + 1;
						end = start;
						current = vec[start].first;
						temp = 0;
					}
					if (i == size - 1)
					{
						ret.push_back(std::pair<int, int>(start, end));
					}
				}
				return ret;
			};
			auto getScore = [&](std::vector<std::pair<int, int>> vec, int start, int end)
			{
				int ret = vec[start].second;
				int dec = ret;
				for (int i = start + 1; i <= end; ++i)
				{
					if (vec[i].second > dec)
					{
						ret = ret + vec[i].second - dec;
						dec = vec[i].second - dec;
					}
					else
					{
						dec = 0;
					}
				}

				return ret;
			};
			std::sort(ary.begin(), ary.end(), compare);
			int ret = 0;
			auto interval = getContinuously(ary);
			for (auto iter : interval)
			{
				ret += getScore(ary, iter.first, iter.second);
			}
			return ret;
		}
	};
};