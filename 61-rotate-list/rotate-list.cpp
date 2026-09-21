class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge cases: empty list, single element, or no rotation needed
        if (!head || !head->next || k == 0) {
            return head;
        }

        // Step 1: Compute the length of the list and find the tail node
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Handle cases where k >= length
        k = k % length;
        if (k == 0) return head; // No rotation needed if k is a multiple of length

        // Step 3: Connect tail to head to form a circle
        tail->next = head;

        // Step 4: Find the new tail node (at position length - k)
        ListNode* new_tail = head;
        for (int i = 1; i < length - k; i++) {
            new_tail = new_tail->next;
        }

        // Step 5: The node after new_tail is the new head
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr; // Break the circle

        return new_head;
    }
};
