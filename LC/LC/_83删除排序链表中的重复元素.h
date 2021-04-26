#pragma once
#include "ListNode.h"
class _83ɾ�����������е��ظ�Ԫ��
{
	class Solution {
	public:
		ListNode* findNext(ListNode* node)
		{
			if (node->next == nullptr)
				return node;
			if (node->val != node->next->val)
				return node;
			auto temp = node->next;
			delete node;
			node = nullptr;
			return findNext(temp);
		}

		ListNode* deleteDuplicates(ListNode* head) {
			if (head = nullptr)
				return head;
			auto node = findNext(head);
			auto temp = node;
			while (temp->next != nullptr)
			{
				temp->next = findNext(temp->next);
				temp = temp->next;
			}
			return node;
		}
	};
};

