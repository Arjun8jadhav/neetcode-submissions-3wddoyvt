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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*> vk;
        vk.push(root);
        vector<vector<int>> ans;
        while(!vk.empty()){
            int size=vk.size();
            vector<int> temp(size);
            for(int i=0;i<size;i++){
                auto it= vk.front();
                vk.pop();
                temp[i]=it->val;
                if(it->left){
                   vk.push(it->left);
                }
                if(it->right){
                    vk.push(it->right);
                }
            }
            ans.push_back(temp);

        }
        return ans;
    }
};
