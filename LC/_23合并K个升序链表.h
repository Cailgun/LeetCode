#pragma once
#include "ListNode.h"
#include <vector>
#include <algorithm>
class _23合并K个升序链表
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

		static ListNode* mergeKLists(std::vector<ListNode*>& lists) {
			std::vector<int> ary;
			for (auto iter : lists)
			{
				auto temp = iter;
				while (temp != nullptr)
				{
					ary.push_back(temp->val);
					temp = temp->next;
				}
			}

			std::sort(ary.begin(), ary.end());
			ListNode* root = nullptr;
			auto temp = root;
			for (auto iter : ary)
			{
				if (root == nullptr)
				{
					root = new ListNode(iter);
					temp = root;
				}
				else
				{
					temp->next = new ListNode(iter);
					temp = temp->next;
				}
			}

			return root;
		}
	};
};

