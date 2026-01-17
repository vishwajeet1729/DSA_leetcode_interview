// Last updated: 1/17/2026, 12:26:54 PM
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
      std::unordered_map<int, int> countMap;

        // Build the count map from nums
        for (int num : nums) {
            countMap[num]++;
        }

        // Dummy node to handle edge cases easily
        ListNode dummy(0);
        dummy.next = head;
        ListNode* current = &dummy;

        while (current->next != nullptr) {
            if (countMap.find(current->next->val) != countMap.end()) {
                // Decrease the count in the map
                // countMap[current->next->val]--;

                // Remove the node
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }

        return dummy.next;
    }
};