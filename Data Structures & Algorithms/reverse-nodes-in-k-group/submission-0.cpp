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
    ListNode* reverse_here(ListNode* test, int limit){
    ListNode* start = test->next;
    ListNode* tail = start;  
    while(limit--){
        ListNode* next = start->next;
        start->next = next->next;
        next->next = test->next; 
        test->next = next;
    }
    return tail; 
}
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* start = new ListNode(0, head);
         ListNode* dummy = start;

         while(true){
   
        ListNode* check = dummy;
        for(int i = 0; i < k; i++){
            check = check->next;
            if(!check) return start->next;  
        }
          ListNode* tail = reverse_here(dummy, k-1);
           dummy = tail;
        }
    return start->next;
}
};
