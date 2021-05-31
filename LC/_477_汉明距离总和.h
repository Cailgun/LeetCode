#pragma once
#include <vector>
#include <algorithm>
class _477_ººÃ÷¾àÀë×ÜºÍ
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
		template<class T>
		int totalHammingDistance(T&& nums) {
			if (nums.size() <= 1)
				return 0;

			std::sort(nums.begin(), nums.end());
			std::vector<std::pair<int, int>> ary;
			int last = nums[0];
			int cnt = 1;
			for (int i = 1; i < nums.size(); ++i)
			{
				if (nums[i] == last)
				{
					cnt++;
					if (i == nums.size() - 1)
					{
						ary.push_back(std::pair<int, int>(last, cnt));
					}
					continue;
				}
				else
				{
					ary.push_back(std::pair<int, int>(last, cnt));
					last = nums[i];
					cnt = 1;
					if (i == nums.size() - 1)
					{
						ary.push_back(std::pair<int, int>(last, cnt));
					}
				}
			}
			if (ary.size() <= 1)
				return 0;

			int ret = 0;
			for (int i = 0; i < ary.size(); ++i)
			{
				for (int j = i + 1; j < ary.size(); ++j)
				{
					ret += hammingDistance(ary[i].first, ary[j].first) * ary[i].second * ary[j].second;
				}
			}
			return ret;
		}
	};
};

