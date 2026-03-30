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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* start=l1,*start2=l2;
        int count1=0,idx=0,count2=0;
        while(start){
            count1+=(pow(10,idx)*start->val);
            idx++;
            start=start->next;
        }
        idx=0;
        while(start2){
            count2+=(pow(10,idx)*start2->val);
            idx++;
            start2=start2->next;
        }
        int fin=count1+count2;
        ListNode* prev=new ListNode(0),*left=NULL;
        ListNode* ans=prev;
        if(fin==0){
            return prev;
        }
        while(fin){
             left=new ListNode(fin%10);
             prev->next=left;
             prev=left;
             fin/=10;
        }
        return ans->next;
    }
};
