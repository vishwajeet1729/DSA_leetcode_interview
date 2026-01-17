// Last updated: 1/17/2026, 12:33:32 PM
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
    ListNode* reverseList(ListNode* head) {
          
          ListNode *h1=head;
          ListNode * back=nullptr;
          while(head){
                
                ListNode* demo=head->next;
                 head->next=back;
                 back=head;
                
                head=demo;
                
          }
       
       return back;

    }
};