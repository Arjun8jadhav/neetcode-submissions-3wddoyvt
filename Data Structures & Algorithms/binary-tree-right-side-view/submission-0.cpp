/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> vk;
        queue<TreeNode*> dq;
        dq.push(root);
        while(!dq.empty()){
            int size=dq.size();
            int prev=-1;
            for(int i=0;i<size;i++){
                auto it=dq.front();
                dq.pop();
                if(it->left){
                    dq.push(it->left);
                }
                if(it->right){
                    dq.push(it->right);
                }
                prev=it->val;
            }
            vk.push_back(prev);
        }
        return vk;

    }
};
