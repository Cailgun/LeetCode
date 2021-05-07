#pragma once
#include <string>
class _12整数转罗马数字
{
	class Solution {
	public:
		static std::string intToRoman(int num) {
			int thousand = num - num % 1000;
			thousand /= 1000;
			num %= 1000;
			int fiveHundred = num - num % 500;
			fiveHundred /= 500;
			num %= 500;
			int hundred = num - num % 100;
			hundred /= 100;
			num %= 100;
			int fifty = num - num % 50;
			fifty /= 50;
			num %= 50;
			int ten = num - num % 10;
			ten /= 10;
			num %= 10;
			int five = num - num % 5;
			five /= 5;
			num %= 5;
			int one = num;

			std::string str = "";
			for (int i = 0; i < thousand; ++i)
			{
				str += "M";
			}
			if (hundred == 4)
			{
				if (fiveHundred == 1)
				{
					str += "CM";
				}
				else
				{
					str += "CD";
				}
			}
			else
			{
				for (int i = 0; i < fiveHundred; ++i)
				{
					str += "D";
				}
				for (int i = 0; i < hundred; ++i)
				{
					str += "C";
				}
			}
			if (ten == 4)
			{
				if (fifty == 1)
				{
					str += "XC";
				}
				else
				{
					str += "XL";
				}
			}
			else
			{
				for (int i = 0; i < fifty; ++i)
				{
					str += "L";
				}
				for (int i = 0; i < ten; ++i)
				{
					str += "X";
				}
			}
			if (one == 4)
			{
				if (five == 1)
				{
					str += "IX";
				}
				else
				{
					str += "IV";
				}
			}
			else
			{
				for (int i = 0; i < five; ++i)
				{
					str += "V";
				}
				for (int i = 0; i < one; ++i)
				{
					str += "I";
				}
			}
			return str;
		}
	};
};

