#pragma once
#include <vector>
using namespace std;

class _1两数之和
{
	class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> ret;
			//将判断两个数之和为target的逻辑改成了寻找第二个数为target-nums[i]的逻辑，加快了速度
			for (int i = 0; i < nums.size(); ++i)
			{
				int t = target - nums[i];
				for (int j = 0; j < nums.size(); ++j)
				{
					if (j == i)
						continue;
					if (nums[j] == t)
					{
						ret.push_back(i);
						ret.push_back(j);
						return ret;
					}
				}
			}
			return ret;
		}
	};
};

