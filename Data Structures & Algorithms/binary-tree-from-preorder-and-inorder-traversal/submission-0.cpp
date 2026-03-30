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
    TreeNode* solve(int idx,int i,int j,vector<int>& preorder,unordered_map<int,int>& vk){
        if(i > j){
            return NULL;
        }
        TreeNode* start=new TreeNode(preorder[idx]);
        int fidIdx=vk[preorder[idx]];
        int next=fidIdx-i;
        start->left=solve(idx+1,i,fidIdx-1,preorder,vk);
        start->right=solve(idx+next+1,fidIdx+1,j,preorder,vk);
        return start;
        

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int> vk;
        for(int i=0;i<n;i++){
           vk[inorder[i]]=i;
        }
        return solve(0,0,n-1,preorder,vk);
    }
};
