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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start=head;
        int count=0;
        ListNode* temp=head, *fin=new ListNode(0);
        fin->next=head;
        ListNode* prev=fin;
        if(!head || !head->next){
            return NULL;
        }
        while(temp){
            count++;
            temp=temp->next;
        }
       
        for(int i=0;i<count-n;i++){
            prev=start;
            start=start->next;
        }
        prev->next=start->next;
        return fin->next ;
    }
};
