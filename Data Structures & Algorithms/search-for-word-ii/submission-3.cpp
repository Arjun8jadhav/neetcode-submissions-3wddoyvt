struct Node{
    vector<Node*> child;
    string fin="";
    Node(){
       child.resize(26,NULL);
    }
};

class Solution {
public:
    void solve(int i,int j,int n,int m,vector<vector<char>>& board,vector<string>& ans,vector<vector<int>>& vis,Node* root){
        if(i<0 || i>=n || j<0 || j>=m){
               return;
        }
        int idx=board[i][j]-'a';
        if(vis[i][j]==1 || !root->child[idx]){
            return;
        }
        vis[i][j]=1;
        root=root->child[idx];
        if(root->fin!=""){
            ans.push_back(root->fin);
            root->fin="";
        }
        solve(i+1,j,n,m,board,ans,vis,root);
        solve(i-1,j,n,m,board,ans,vis,root);
        solve(i,j+1,n,m,board,ans,vis,root);
        solve(i,j-1,n,m,board,ans,vis,root);
        vis[i][j]=0;
    }
    void buildTrie(int i,string word,Node* root){
        int n=word.length();
        for(int i=0;i<n;i++){
            if(!root->child[word[i]-'a']){
                root->child[word[i]-'a']=new Node();
            }
            root=root->child[word[i]-'a'];
        }
        root->fin=word;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size(),m=board[0].size();
        Node* root=new Node();
        for(auto& it: words){
            buildTrie(0,it,root);
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<string> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(i,j,n,m,board,ans,vis,root);
            }
        }
        return ans;

    }
};
