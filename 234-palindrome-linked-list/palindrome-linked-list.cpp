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

    // Reversing LL
    ListNode* reverseLL(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        
        ListNode* newhead = reverseLL(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newhead;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1 : to locate the mid of LL
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2 : To reverse the second half
        ListNode* newhead = reverseLL(slow->next);

        // Step 3 : Comparing the First half and Second Half

        ListNode* first = head;
        ListNode* second = newhead;

        while(second)
        {
            if(first->val != second->val)
            {
                reverseLL(newhead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        reverseLL(newhead);
        return true;
    }
};