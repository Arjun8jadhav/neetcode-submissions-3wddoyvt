class Solution {
public:
    vector<string> smap={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(int idx,string& digits,string& temp,vector<string>& ans){
        if(idx==digits.length()){
            if(temp.length()>0){
               ans.push_back(temp);
            }
            return;
        }
        int idy=digits[idx]-'2';
        string recurse=smap[idy];
        for(int i=0;i<recurse.length();i++){
            temp+=recurse[i];
            solve(idx+1,digits,temp,ans);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> vk;
        string temp="";
        solve(0,digits,temp,vk);
        return vk;
    }
};
