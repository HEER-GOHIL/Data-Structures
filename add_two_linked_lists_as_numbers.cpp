class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Final=NULL;
        int carry=0;
        while(l1||l2)
        {
            
            int val1=l1?l1->val:0;
            int val2=l2?l2->val:0;
            int sum=val1+val2+carry;
            if(sum>9)
            {
                carry=sum/10;
                if(Final==NULL)
                {
                    Final= new ListNode(sum%10);
                }
                else
                {
                    ListNode* f=Final;
                    while(f->next!=NULL)
                        f=f->next;
                    f->next=new ListNode(sum%10);
                }
            }
            else
            {
                
                if(Final==NULL)
                {
                    Final=new ListNode(sum);
                }
                else
                {
                    ListNode* f=Final;
                    while(f->next!=NULL)
                        f=f->next;
                    f->next=new ListNode(sum);
                }
            }
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
            carry=sum/10;
        }
        if(carry)
        {
            ListNode* f=Final;
            while(f->next!=NULL)
                f=f->next;
            f->next=new ListNode(carry);
        }
    return Final;
    }
};
