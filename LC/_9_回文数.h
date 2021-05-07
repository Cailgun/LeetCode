#pragma once
#include <vector>
using namespace std;
class _9������
{
	class Solution {
	public:
		bool isPalindrome(int x) {
			//�����϶����ǻ�����
			if (x < 0)
				return false;
			//С��10��������һ���ǻ����� 
			if (x < 10)
				return true;
			//Ȼ��������������ÿһλ���������ٰ��Ű��űȽ���Ӧλ�õ����Ƿ����
			vector<long long> vec;
			long long mod = 1;
			while (x != 0)
			{
				long long temp = (x % (mod * 10)) / mod;
				vec.push_back(temp);
				x = x - temp * mod;
				mod *= 10;
			}
			//��ͷ��������β���������űȽϣ�����β�������һ��Ԫ�صĺ�һλ�����Ҫ��--
			auto iterbegin = vec.begin();
			auto iterend = vec.end();
			iterend--;
			while (iterbegin != iterend)
			{
				if (*iterbegin != *iterend)
					return false;
				else
				{
					iterbegin++;
					//�����������������ˣ���˵�����е������Ƚ����ˣ���������ѭ��
					if (iterend == iterbegin)
						break;
					iterend--;
				}
			}
			return true;
		}
	};
};

