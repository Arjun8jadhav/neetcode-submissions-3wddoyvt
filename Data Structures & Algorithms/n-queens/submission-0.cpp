class Solution {
public:
    bool isValid(int i,int j,int n,vector<string>& valid){
        int i_=i-1,j_=j-1;
        while(i_>=0 && j_>=0){
            if(valid[i_][j_]=='Q'){
                return false;
            }
            i_--;
            j_--;
        }
        i_=i-1,j_=j+1;
        while(i_>=0 && j_<n){
            if(valid[i_][j_]=='Q'){
                return false;
            }
            i_--;
            j_++;
        }
        return true;
    }
    void solve(int idx,int n,vector<int> & col,string& temp,vector<string>& valid,vector<vector<string>>& ans){
        if(idx==n){
            ans.push_back(valid);
            return;
        }
        for(int i=0;i<n;i++){
            if(col[i]==0 && isValid(idx,i,n,valid)){
                  col[i]=1;
                  temp[i]='Q';
                  valid.push_back(temp);
                  temp[i]='.';
                  solve(idx+1,n,col,temp,valid,ans);
                  col[i]=0;
                  valid.pop_back();

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // vector<int> row(n,0);
        vector<int> col(n,0);
        vector<string> valid;
        vector<vector<string>> ans;
        string temp="";
        for(int i=0;i<n;i++){
            temp+='.';
        }
        solve(0,n,col,temp,valid,ans);
        return ans;
    }
};
