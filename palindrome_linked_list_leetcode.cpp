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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;
        slow = reverse(slow);
        while(slow!=NULL)
        {
            if(slow->val!=fast->val)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
            
        }
        return true;
        
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        while(head!=NULL)
        {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
        
    }
};
