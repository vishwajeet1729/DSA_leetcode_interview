// Last updated: 1/17/2026, 12:33:53 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         ListNode* h1=head;
         if(head==NULL||head->next==NULL)return 0;
         while(head!=NULL&&head->next!=NULL){
              head=head->next->next;
              h1=h1->next;
              if(h1==head)return 1;
         }      
               return 0;
    }
};