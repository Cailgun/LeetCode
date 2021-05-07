#pragma once
#include "ListNode.h"
#include <utility>
class _25K个一组翻转链表
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
		static ListNode* reverseKGroup(ListNode* head, int k) {
			if (head == nullptr || head->next == nullptr)
			{
				return head;
			}
			auto temp = head;
			int count = 0;
			while (temp != nullptr)
			{
				count++;
				temp = temp->next;
			}

			if (count < k || k == 1)
			{
				return head;
			}
			temp = head;
			std::pair<ListNode*, ListNode*> last(nullptr, nullptr);

			ListNode* newHead = nullptr;
			while (count >= k)
			{
				int i = k;
				auto temp2 = temp;
				while (i-- > 0)
				{
					temp2 = temp2->next;
				}
				auto var = revertList(temp, k);
				if (newHead == nullptr && last.second != nullptr)
				{
					newHead = last.second;
				}
				last.second = var.second;
				if (newHead != nullptr)
				{
					last.first->next = last.second;
					last.first = var.first;
				}
				last.first = var.first;
				temp = temp2;
				count -= k;
			}
			last.first->next = temp;
			return newHead ? newHead : last.second;
		}

		static std::pair<ListNode*, ListNode*> revertList(ListNode* head, int k)
		{
			std::pair<ListNode*, ListNode*> ret(head, nullptr);
			auto temp1 = head;
			auto temp2 = head->next;
			head->next = nullptr;
			while (k-- > 1)
			{
				auto temp3 = temp1;
				temp1 = temp2->next;
				temp2->next = temp3;
				if (temp1 != nullptr && k != 1)
					std::swap(temp1, temp2);
			}
			ret.second = temp2;
			return ret;

		}
	};
};

