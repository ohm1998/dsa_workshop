/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode *res=NULL;
    
    int carry=0;
    while(l1 || l2)
    {
        int first=0,second=0;
        if(l1==NULL)
        {
            first=0;
        }
        else
        {
            first = l1->val;
            l1 = l1->next;
        }
        if(l2==NULL)
        {
            second = 0;
        }
        else
        {
            second = l2->val;
            l2 = l2->next;
        }
        int sum = first+second + carry;
        carry = sum/10;
        sum = sum%10;
        struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        
        new_node->val = sum;
        new_node->next = NULL;
        if(res==NULL)
        {
            res = new_node;
        }
        else
        {
            //new_node->next = res;
            //res = new_node;
            struct ListNode *curr;
            curr = res;
            while((curr->next)!=NULL)
            {
                curr = curr->next;
            }
            curr->next = new_node;
        }
    }
    if(carry!=0)
    {
         struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = carry;
        new_node->next = NULL;
        struct ListNode *curr;
            curr = res;
            while((curr->next)!=NULL)
            {
                curr = curr->next;
            }
            curr->next = new_node;
    }
    return res;
}
