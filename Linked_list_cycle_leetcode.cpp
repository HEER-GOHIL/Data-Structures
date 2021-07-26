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
        if(head==NULL)
        {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(true)
        {
            if(slow->next==NULL || fast->next==NULL)
            {
                return false;
            }
            slow = slow->next;
            if(fast->next->next!=NULL)
            {
            fast = fast->next->next;
            }
            else
            {
                return false;
            }
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
};
