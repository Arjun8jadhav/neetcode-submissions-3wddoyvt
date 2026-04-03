/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* solve(Node* node,unordered_map<Node*,Node*>& vk){
        if(vk.count(node)){
            return vk[node];
        }
        Node* copy=new Node(node->val);
        vk[node]=copy;
        for(auto& it: node->neighbors){
            copy->neighbors.push_back(solve(it,vk));
        }
        return copy;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> vk;
        return !node?NULL:solve(node,vk);
    }
};
