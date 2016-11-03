#2016/10/31
#双指针思想，需要注意的是，对头指针的定义
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head ==NULL)
            return NULL;
        ListNode* pPrev=NULL;
        ListNode* p=head;
        ListNode* q=head;
        for(int i=0;i<n-1;i++){
            q = q->next;
        }
        while(q->next){
            pPrev = p;
            p = p->next;
            q = q->next;
        }
        if(pPrev==NULL){
            head=p->next;
            delete p;
        }
        else{
            pPrev->next=p->next;
            delete p;
        }
        return head;
    }
};