#pragma once
#include "ListNode.h"
#include <vector>
class _24两两交换链表中的节点
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
		static ListNode* swapPairs(ListNode* head) {
			if (head == nullptr || head->next == nullptr)
			{
				return head;
			}
			std::vector<ListNode*> vec;
			auto temp = head;
			while (temp != nullptr)
			{
				vec.push_back(temp);
				temp = temp->next;
			}
			if (vec.size() == 1)
			{
				return head;
			}

			for (int i = 0; i < vec.size(); i += 2)
			{
				if (i == vec.size() - 1)
				{
					break;
				}
				std::swap(vec[i], vec[i + 1]);

			}
			for (int i = 0; i < vec.size() - 1; ++i)
			{
				vec[i]->next = vec[i + 1];
			}
			vec[vec.size() - 1]->next = nullptr;
			return vec[0];
		}
	};
};

