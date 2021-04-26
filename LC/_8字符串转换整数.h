#pragma once
#include <vector>
#include <string>
using namespace std;
class _8�ַ���ת������
{
	class Solution {
	public:
		int myAtoi(string str) {
			//ʹ��������������stringת��int��ÿһλ�ϵ�����
			vector<int> vec;
			//symbol�ж��Ƿ��Ǹ�����false���Ǹ�����Ĭ��Ϊ��
			bool symbol = true;
			//���ڳ���INT_MAX����INT_MINҪ����INT_MAX����INT_MIN�����ʹ��longlong���Ƚϴ�С
			long long result = 0;
			//�ҵ���һ���ǿ��ַ����±꣬�浽neof
			int neof;
			//�ҷǿ��ַ�
			for (int i = 0; i < str.length(); ++i)
			{
				if (str[i] == ' ')
					continue;
				else
				{
					neof = i;
					break;
				}
			}
			//�жϵ�һ���ǿ��ַ��Ƿ���Ч����Чֱ�ӷ��أ�˳���ж�ֵ��������
			if ((str[neof] != '-' && str[neof] != '+') && (str[neof] < '0' || str[neof] > '9'))
				return 0;
			else if (str[neof] == '-')
			{
				symbol = false;
				neof++;
			}
			else if (str[neof] == '+')
			{
				symbol = true;
				neof++;
			}
			bool temp = true;
			//�����ҵ���һ����Ч���֣�����-00000000000001����-1�����Ҫ��0��������1��ʼ��¼
			//Ȼ����һ����ǣ���ֹ�������Ч0Ҳ��������
			//���Ž����ִ浽�����У�����ascii������-48����ʵ��ֵ��������� str[neof]-48 �Ĳ���
			for (; neof < str.length(); neof++)
			{
				if (temp)
				{
					if (str[neof] != '0')
						temp = false;
					if (temp)
						continue;
				}
				if (str[neof] >= '0' && str[neof] <= '9')
					vec.push_back(str[neof] - 48);
				else
					break;
			}
			//�ж������Ƿ�Ϊ�գ��վ�ֱ�ӷ���
			if (vec.begin() == vec.end())
				return 0;
			auto iter = vec.end();
			iter--;
			long long c = 1;
			//�Ӹ�λ�����μӵ�ĩλ
			for (iter; iter != vec.begin(); iter--)
			{
				result += *iter * c;
				c *= 10;
				if (c > INT_MAX)
				{
					return symbol ? INT_MAX : INT_MIN;
				}
			}
			//�ж������Լ��Ƿ�Խ��
			result += vec[0] * c;
			if (!symbol)
				result = 0 - result;
			if (result > INT_MAX)
				return INT_MAX;
			if (result < INT_MIN)
				return INT_MIN;
			return result;
		}
	};
};

