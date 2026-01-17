// Last updated: 1/17/2026, 12:31:00 PM
class Solution {
    public int getDecimalValue(ListNode head) {
        int result = head.val;
        while (head.next != null) {
            result = result * 2 + head.next.val;
            head = head.next;
        }
        return result;
    }
}