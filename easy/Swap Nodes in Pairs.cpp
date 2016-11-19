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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        //第一次有点特殊
        ListNode* t = head;
        ListNode* p = head->next;
        ListNode* q = head->next->next;
        cout<<(q==NULL)<<endl;
        int No = 0;
        while(1){
            //cout<<"wujs"<<endl;
            t->next = q;
           
            if(No==0){
                p->next = t;
                head=p;
                cout<<"No=="<<head->val<<endl;
            }
            else{
                p->next = q->next;
                q->next=p;
                t = t->next;
                t = t->next;
            }
            //cout<<"right..."<<endl;
            No+=1;
            //cout<<"t val:"<<t->val<<endl;
            //cout<<"t->next"<<(t->next==NULL)<<endl;
            if(t->next==NULL)
                break;
            p = t->next;
            //cout<<"p val:"<<p->val<<endl;
            if(p->next ==NULL){
                break;
            }else{
                 q= p->next;
            }
            
        }
      return head;  
    }
};