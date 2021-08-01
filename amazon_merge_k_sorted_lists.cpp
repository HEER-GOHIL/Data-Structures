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
#include<vector>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       
        ListNode* mlist = new ListNode();
        if(lists.size()==0)
        {
            return mlist->next;    
        }
        mlist = lists[0];
        for(int i=1;i<lists.size();i++)
        {
            mlist = merge2(mlist,lists[i]);
        }
        return mlist;
        
    }
    ListNode* merge2(ListNode* list1, ListNode* list2)
    {
        ListNode* retlist = new ListNode();
        ListNode* hretlist = retlist;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                retlist->next = list1;
                retlist = retlist->next;
                list1 = list1->next;
            }
            else
            {
                retlist->next = list2;
                retlist = retlist->next;
                list2 = list2->next;
            }
        }
        if(list1!=NULL)
        {
            retlist->next = list1;
        }
        if(list2!=NULL)
        {
            retlist->next = list2;
        }
        return hretlist->next;
    }
};
