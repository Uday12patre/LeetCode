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
    ListNode *detectCycle(ListNode *head) {
        // Empty List or list with one node

        if(!head || !head->next)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        bool hasCycle = false;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
            {
                hasCycle = true;
                break;
            }
        }

        if(!hasCycle)
            return NULL;

        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};