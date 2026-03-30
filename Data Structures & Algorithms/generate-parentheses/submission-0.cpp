class Solution {
public:
    void solve(string s,int ones,int count,int n,vector<string>& ans){
        if(ones==n && count==0){
            ans.push_back(s);
            return;
        }
        if(ones<n){
            solve(s+"(",ones+1,count+1,n,ans);
        }
        if(count>0){
            solve(s+")",ones,count-1,n,ans);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("",0,0,n,ans);
        return ans;
    }
};
