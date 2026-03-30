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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1=list1,*prev1=new ListNode(0), *head2=list2;
        prev1->next=head1;
        if(!list1){
            return list2;
        }
        ListNode* start=prev1;
        while(head1 && head2){
            if(head1->val<=head2->val){
                prev1=head1;
                head1=head1->next;
            }
            else{
                ListNode* next2=head2->next;
                head2->next=head1;
                prev1->next=head2;
                prev1=head2;
                head2=next2;
            }
        }
        if(head2) prev1->next = head2;
        return start->next;
    }
};
