// Last updated: 1/17/2026, 12:35:16 PM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
ListNode dummy(0, head); 
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
         for (int i = 0; i < n + 1; i++) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        return dummy.next; 
    }
};