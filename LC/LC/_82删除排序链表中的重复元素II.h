#pragma once
#include "ListNode.h"
class _82删除排序链表中的重复元素II
{
	class Solution {
	public:
		ListNode* findNext(ListNode* node, int val, bool b = false)
		{
			if (node->next == nullptr)
			{
				if (b && node->val == val)
				{
					delete node;
					return nullptr;
				}
				else
				{
					return node;
				}
			}
			if (b)
			{
				if (node->val == val)
				{
					auto temp = node->next;
					delete node;
					node = nullptr;
					return findNext(temp, val, b);
				}
				else
				{
					return findNext(node, node->val);
				}
			}
			if (node->val != node->next->val)
			{
				return node;
			}
			else
			{
				b = true;
				auto temp = node->next;
				delete node;
				node = nullptr;
				return findNext(temp, val, b);
			}
		}

		ListNode* deleteDuplicates(ListNode* head) {
			if (head == nullptr)
				return head;
			auto node = findNext(head, head->val);
			if (node == nullptr)
			{
				return nullptr;
			}
			auto temp = node;
			while (temp->next != nullptr)
			{
				temp->next = findNext(temp->next,temp->next->val);
				if (temp->next == nullptr)
					break;
				temp = temp->next;
			}
			return node;
		}
	};
};

