#pragma once
#include "ListNode.h"
#include <vector>

class _92·´×ªÁ´±íII {
	class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int left, int right) {
			if (left == right) {
				return head;
			}

			auto current = head;
			std::vector<ListNode*> vec;
			while (current != nullptr)
			{
				vec.push_back(current);
				current = current->next;
			}

			for (int i = right - 1; i > left - 1; --i)
			{
				vec[i]->next = vec[i - 1];
			}
			if (vec.size() == right)
			{
				vec[left - 1]->next = nullptr;
			}
			else
			{
				vec[left - 1]->next = vec[right];
			}

			if (left == 1)
			{
				return vec[right - 1];
			}
			vec[left - 2]->next = vec[right - 1];
			return vec[0];
		}
	};
};

