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
      int carry=0;
      ListNode* start=new ListNode(0),*prev=NULL;
      ListNode* left=start;
      while(l1 || l2 || carry){
        int num=carry;
        if(l1){
           num+=(l1->val);
           l1=l1->next;
        }
        if(l2){
          num+=(l2->val);
          l2=l2->next;
        }
        carry=num/10;
        cout<<num%10<<endl;
        prev=new ListNode(num%10);
        left->next=prev;
        left=prev;
        
      }
      return start->next;
    }
};
