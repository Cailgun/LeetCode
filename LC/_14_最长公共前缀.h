#pragma once
#include <string>
#include <vector>
class _14最长公共前缀
{
	class Solution {
	public:
		static std::string longestCommonPrefix(std::vector<std::string>& strs) {
			unsigned int maxLength = 0;
			for (auto iter : strs)
			{
				maxLength = iter.length() > maxLength ? iter.length() : maxLength;
			}

			unsigned int maxSame = 0;
			bool shouldBreak = false;
			for (int i = 0; i < maxLength; ++i)
			{
				char ch = strs[0][i];
				for (auto iter : strs)
				{
					if (iter[i] != ch)
					{
						shouldBreak = true;
						break;
					}
				}
				if (shouldBreak)
				{
					break;
				}
				maxSame++;
			}
			std::string str = "";
			for (int i = 0; i < maxSame; ++i)
			{
				str += strs[0][i];
			}

			return str;
		}
	};
};

