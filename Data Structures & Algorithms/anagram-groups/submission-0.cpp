class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> vk;
        unordered_set<string> unique;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            vk[temp].push_back(strs[i]);
            unique.insert(temp);
            
        }
        vector<vector<string>> ans;
        for(auto & it: unique){
            vector<string> dummy;
            for(auto & tt: vk[it]){
                dummy.push_back(tt);
            }
            ans.push_back(dummy);
        }
        return ans;
    }
};
