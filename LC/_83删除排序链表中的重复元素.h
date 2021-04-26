#pragma once
#include "ListNode.h"
class _83删除排序链表中的重复元素
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

