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
    ListNode* collisionPoint(ListNode* smaller, ListNode* larger, int n)
    {
        for(int i = 0; i < n; i++)
        {
            if(!larger) return NULL;
            larger = larger->next;
        }

        while(larger && smaller)
        {
            if(larger == smaller)
                return larger;

            larger = larger->next;
            smaller = smaller->next;
        }

        return NULL;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int n1 = 0, n2 = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1)
        {
            n1++;
            temp1 = temp1->next;
        }

        while(temp2)
        {
            n2++;
            temp2 = temp2->next;
        }

        if(n1 > n2)
            return collisionPoint(headB, headA, n1-n2);
        else
            return collisionPoint(headA, headB, n2-n1);

        return NULL;
    }
};