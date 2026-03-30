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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mini=min(p->val,q->val),maxi=p->val+q->val-mini;
        if(mini<=root->val && maxi>=root->val){
            return root;
        }
        if(mini>root->val && maxi>root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return lowestCommonAncestor(root->left,p,q);
    }
};
