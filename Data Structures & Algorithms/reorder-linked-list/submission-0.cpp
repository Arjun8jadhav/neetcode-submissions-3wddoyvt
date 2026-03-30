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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL,*start=head;
        while(head){
           start=head->next;
           head->next=prev;
           prev=head;
           head=start;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
       ListNode* slow=head,*fast=head;
       while(fast && fast->next){
         slow=slow->next;
         fast=fast->next?fast->next->next:NULL;
       }
       ListNode* start1=head, * start2=slow->next;
       slow->next=NULL;
       start2= reverseList(start2);
       while(start2){
          ListNode* next1=start1->next;
          start1->next=start2;
          start1=next1;
          ListNode* next2=start2->next;
          start2->next=start1;
          start2=next2;

       }


        
    }
};
