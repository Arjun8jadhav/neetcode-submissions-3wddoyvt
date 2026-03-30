class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
   
        unordered_map<int,int> vk;
        int n=nums.size();
        for(int i=0;i<n;i++){
            vk[nums[i]]++;
        }
        vector<vector<int>> freq(n+1);
        for(auto & it: vk){
            freq[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int j=n;j>=0 && k;j--){
            if(freq[j].size()>0){
               for(auto it : freq[j]){
                   k--;
                   ans.push_back(it);
                   if(k==0){
                      break;
                   }
               }
            }
        }
        return ans;

    }
};
