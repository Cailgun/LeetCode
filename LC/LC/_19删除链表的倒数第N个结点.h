#pragma once
#include "ListNode.h"
#include <vector>
class _19删除链表的倒数第N个结点
{
	class Solution {
	public:


		static ListNode* removeNthFromEnd(ListNode* head, int n) {
			auto temp = head;
			std::vector<ListNode*> vec;
			while (temp != nullptr)
			{
				vec.push_back(temp);
				temp = temp->next;
			}
			auto size = vec.size();
			if (n == 1 && size > 1)
			{
				vec[size - 2]->next = nullptr;
			}
			else if (n == size) {
				if (size == 1)
				{
					return nullptr;
				}
				return vec[1];
			}
			else {
				vec[size - n - 1]->next = vec[size - n + 1];
				delete vec[size - n];
				vec[size - n] = nullptr;
			}

			return head;
		}
	};
};

