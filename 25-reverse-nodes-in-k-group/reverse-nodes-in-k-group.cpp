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

    ListNode* getKthNode(ListNode* temp, int k)
    {
        k -= 1;
        while(temp != NULL && k > 0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }
 
    // recursive reversing the k-group list 
    ListNode* reverseKlist(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* newhead = reverseKlist(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newhead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp)
        {
            ListNode* KthNode = getKthNode(temp, k);

            if(KthNode == NULL)
            {
                if(prevLast)
                {
                    prevLast->next = temp;
                    break;
                }
            }

            ListNode* nextNode = KthNode->next;
            KthNode->next = NULL;

            reverseKlist(temp);
            if(temp == head)
            {
                head = KthNode;
            }
            else
            {
                prevLast->next = KthNode;
            }

            prevLast = temp;
            temp = nextNode;

        }
        return head;
    }
};