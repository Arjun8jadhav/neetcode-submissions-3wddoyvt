/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> vk;
        Node* dummy= head;
        while(dummy){
            if(!vk.count(dummy)){
                Node* node=new Node(dummy->val);
                vk[dummy]=node;
            }
            if(dummy->next){
                if(!vk.count(dummy->next)){
                   Node* node1=new Node(dummy->next->val);
                   vk[dummy->next]=node1;
                   
                }
                vk[dummy]->next=vk[dummy->next];
            }
            if(dummy->random){
               if(!vk.count(dummy->random)){
                  Node* node2=new Node(dummy->random->val);
                  vk[dummy->random]=node2;
               }
               vk[dummy]->random=vk[dummy->random];
            }
         //   cout<<dummy->val;
            dummy=dummy->next;

        }
        return vk[head];
    }
};
