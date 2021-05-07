#pragma once
#include <vector>
class _1720_�������������
{
	class Solution {
	public:
		std::vector<int> decode(std::vector<int>& encoded, int first) {
			std::vector<int> ret;
			ret.push_back(first);
			for (auto iter : encoded)
			{
				ret.push_back(*ret.rbegin() ^ iter);
			}
			return ret;
		}
	};
};

