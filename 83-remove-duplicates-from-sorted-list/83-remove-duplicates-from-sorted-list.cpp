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
    ListNode* deleteDuplicates(ListNode* head)
{
	if (!head) return nullptr;

	ListNode* cur(head);

	while (cur)
	{
		// we keep searching the next node that does not have the same value as cur
		while (cur->next && cur->next->val == cur->val)	// we need to ensure cur->next exists
		{
			auto del(cur->next);
			cur->next = cur->next->next;
			delete del;
		}

		cur = cur->next;
	}

	return head;
}
};