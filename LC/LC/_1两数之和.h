#pragma once
#include <vector>
using namespace std;

class _1����֮��
{
	class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> ret;
			//���ж�������֮��Ϊtarget���߼��ĳ���Ѱ�ҵڶ�����Ϊtarget-nums[i]���߼����ӿ����ٶ�
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

