#pragma once
#include <vector>
class 面试题17_21_直方图的水量
{
	class Solution {
	public:
		int findNext(std::vector<int>& height, int currentPos)
		{
			size_t size = height.size();
			int maximum = INT_MIN;
			int maxPos = 0;
			for (int i = currentPos + 1; i < size; ++i)
			{
				if (height[i] >= height[currentPos])
				{
					return i;
				}
				else if (height[i] > maximum)
				{
					maximum = height[i];
					maxPos = i;
				}
			}
			return maxPos;
		}

		int trap(std::vector<int>& height) {
			size_t size = height.size();
			if (size < 1)
			{
				return 0;
			}

			int capacity = 0;
			for (int currentPos = 0; currentPos != size - 1;)
			{
				int nextPos = findNext(height, currentPos);
				int water = (nextPos - currentPos - 1) * std::min(height[currentPos], height[nextPos]);
				for (int i = currentPos + 1; i < nextPos; ++i)
				{
					water -= height[i];
				}
				capacity += water;
				currentPos = nextPos;
			}
			return capacity;
		}
	};
};

