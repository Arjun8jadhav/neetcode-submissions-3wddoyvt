class Solution {
public:
    bool solve(int i,int j,int idx,string& word,vector<vector<char>>& board,vector<vector<int>>& vis,int& n,int& m){
        if(idx==word.size()-1){
            if(board[i][j]==word[idx]){
                return true;
            }
            return false;
        }
        if(board[i][j]!=word[idx]){
          return false;
        }
        bool left=false,top=false,right=false,bottom=false;
        if(i-1>=0 && !vis[i-1][j]){
          vis[i-1][j]=1;
          left=solve(i-1,j,idx+1,word,board,vis,n,m);
          vis[i-1][j]=0;
    
        }
        if(i+1<n && !vis[i+1][j]){
          vis[i+1][j]=1;
          right=solve(i+1,j,idx+1,word,board,vis,n,m);
          vis[i+1][j]=0;
        }
        if(j+1<m && !vis[i][j+1]){
          vis[i][j+1]=1;
          top=solve(i,j+1,idx+1,word,board,vis,n,m);
          vis[i][j+1]=0;
        }
        if(j-1>=0 && !vis[i][j-1]){
          vis[i][j-1]=1;
          bottom=solve(i,j-1,idx+1,word,board,vis,n,m);
          vis[i][j-1]=0;
        }
        return left || right || bottom || top;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    if(solve(i,j,0,word,board,vis,n,m)){
                        return true;
                    }
                    vis[i][j]=0;
                }
            }
        }
        return false;
    }
    
};
