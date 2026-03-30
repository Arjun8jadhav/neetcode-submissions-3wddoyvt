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
    ListNode* solve_it(ListNode* fin,ListNode* prev){
         if(!fin){
            return prev;
         }
         if(!prev){
            return fin;
         }
         ListNode* ans=new ListNode(-1001,fin);
         ListNode* test=ans;
         while(fin && prev){
             if(fin->val>=prev->val){
                test->next=prev;
                ListNode* next=prev->next;
                prev->next=fin;
                test=prev;
                prev=next;
             }
             else{
                test=fin;
                fin=fin->next;
             }
         }
         if(prev){
            test->next=prev;
         }
         return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         ListNode * fin=NULL;
         int n=lists.size();
         for(int i=0;i<n;i++){
              fin=solve_it(fin,lists[i]);
         }
         return fin;

    }
};
