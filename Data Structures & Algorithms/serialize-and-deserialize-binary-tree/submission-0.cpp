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

class Codec {
public:
    string encodeThis(TreeNode* root){
        if(!root){
            return "N,";
        }
        string str=to_string(root->val);
        str+=",";
        str+=encodeThis(root->left);
        str+=encodeThis(root->right);
        return str;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return encodeThis(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* DecodeThis(string data,int & idx,int n){
        if(data[idx]=='N'){
            idx+=2;
            return NULL;
        }
        int temp=idx;
        while(temp<n && data[temp]!=','){
            temp++;
        }
        TreeNode* t1=new TreeNode(stoi(data.substr(idx,temp-idx)));
        idx=temp+1;
        t1->left=DecodeThis(data,idx,n);
        t1->right=DecodeThis(data,idx,n);
        return t1;

        
    }
    TreeNode* deserialize(string data) {
        int n=data.length();
        int idx=0;
        return DecodeThis(data,idx,n);
    }
};
