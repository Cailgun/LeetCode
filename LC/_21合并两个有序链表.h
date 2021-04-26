#pragma once
class _21合并两个有序链表
{
	/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
	class Solution {
	public:
		class ListNode {
		public:
			int val;
			ListNode* next;
			ListNode() : val(0), next(nullptr) {}
			ListNode(int x) : val(x), next(nullptr) {}
			ListNode(int x, ListNode* next) : val(x), next(next) {}
		};
		static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			auto p1 = l1;
			auto p2 = l2;
			ListNode* lst = new ListNode();
			if (p1->val <= p2->val)
			{
				lst->val = p1->val;
				p1 = p1->next;
			}
			else
			{
				lst->val = p2->val;
				p2 = p2->next;
			}
			auto temp = lst;

			while (p1 != nullptr || p2 != nullptr)
			{
				if (p1 == nullptr | p1->val > p2->val)
				{
					temp->next = new ListNode(p2->val);
					p2 = p2->next;
					temp = temp->next;
				}
				else if (p2 == nullptr || p1->val <= p2->val)
				{
					temp->next = new ListNode(p1->val);
					p1 = p1->next;
					temp = temp->next;
				}
			}

			return lst;
		}
	};
};

