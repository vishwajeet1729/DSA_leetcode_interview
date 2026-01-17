// Last updated: 1/17/2026, 12:31:52 PM
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
    ListNode* middleNode(ListNode* head) {
             ListNode*h1=head;
            while(h1&&h1->next){
                  
                  h1=h1->next->next;
                  head=head->next;
            }
            return head;


    }
};