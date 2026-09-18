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
    void deleteNode(ListNode* node) {

        // Copied the next node into temp
        ListNode* temp = node->next;

        // Copied the value of next node into the previous
        node->val = temp->val;

        // pointed the next node to temp->next
        node->next = temp->next;

        // free the memory
        delete temp;
    }
};