// Last updated: 1/17/2026, 12:35:13 PM
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;  // Edge case: No reversal needed

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        ListNode* curr = head;
        
        // Count total number of nodes
        int n = 0;
        while (curr) {
            n++;
            curr = curr->next;
        }
        
        curr = head; // Reset pointer
        while (n >= k) {  // Process full k-sized groups
            ListNode* prev = nullptr, *groupStart = curr;
            
            // Reverse k nodes
            for (int i = 0; i < k; i++) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            
            // Connect reversed segment
            prevGroupEnd->next = prev;
            groupStart->next = curr;
            prevGroupEnd = groupStart;  // Move the previous group end pointer
            
            n -= k;  // Reduce remaining node count
        }

        return dummy->next;
    }
};
