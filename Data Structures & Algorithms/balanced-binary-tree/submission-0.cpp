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
    bool checked=true;
    int solve(TreeNode* root){
        if(!root || !checked){
            return -1;
        }
        int left=1+solve(root->left);
        int right=1+ solve(root->right);
        if(abs(right-left)>1){
            checked=false;
        }
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        solve(root);
        return checked;
    }
};
