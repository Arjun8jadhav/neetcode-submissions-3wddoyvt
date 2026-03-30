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
    bool solve(TreeNode* root,TreeNode* subroot){
        if(!root && !subroot){
            return true;
        }
        if(!root || !subroot){
            return false;
        }
        if(root->val!=subroot->val){
            return false;
        }
        return (solve(root->left,subroot->left) && solve(root->right,subroot->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool checked=false;
        if(!root){
           return false;
        }
        if(root->val==subRoot->val){
            checked=solve(root,subRoot);
        }
        return checked || isSubtree(root->right,subRoot) || isSubtree(root->left,subRoot);
    }
};
