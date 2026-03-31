class Solution {
public:
    bool palindrome(string temp){
        int i=0,j=temp.length()-1;
        while(i<j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int idx,string str,string s,
        vector<string>& temp,vector<vector<string>>& ans){
        if(idx==s.length() && str==""){
             ans.push_back(temp);
             return;
        }
        if(idx==s.length()){
            return;
        }
        str.push_back(s[idx]);
        solve(idx+1,str,s,temp,ans);
        if(palindrome(str)){
            temp.push_back(str);
            solve(idx+1,"",s,temp,ans);
            temp.pop_back();

        }


    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        string str="";
        solve(0,str,s,temp,ans);
        return ans;
    }
};
