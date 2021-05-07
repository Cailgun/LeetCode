#include <iostream>
#include <vector>
#include <io.h>
#include <functional>
#include <algorithm>
using namespace std;

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
		return frt.second > sec.second;
	};
	std::sort(ary.begin(), ary.end(), compare);
	std::vector<int> hit;
	int ret = 0;
	for (auto iter : ary)
	{
		bool hitTest = false;
		for (auto iterHit : hit)
		{
			if (iterHit == iter.first)
			{
				hitTest = true;
				break;
			}
		}
		if (!hitTest)
		{
			ret += iter.second;
			hit.push_back(iter.first + 1);
			hit.push_back(iter.first - 1);
		}
	}
	return ret;
}

int main()
{
	std::vector<int> v({ 8,3,4,7,6,6,9,2,5,8,2,4,9,5,9,1,5,7,1,4 });
	deleteAndEarn(v);
	return 0;
}