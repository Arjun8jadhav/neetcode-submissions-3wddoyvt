class Solution {
public:
    void solve(int idx,vector<int>& nums, int target,vector<int>& temp,vector<vector<int>>& ans,int & n){
        if(idx>=n){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(target<0){
            return;
        }
        int next_idx=idx;
        int count=0;
        while(next_idx<n && nums[idx]==nums[next_idx]){
            next_idx++;
            count++;
        }
        solve(next_idx,nums,target,temp,ans,n);
        int rem= target/nums[idx];
        for(int i=1;i<=min(rem,count);i++){
            temp.push_back(nums[idx]);
            solve(next_idx,nums,target-i*nums[idx],temp,ans,n);
        }
        for(int i=1;i<=min(rem,count);i++){
          temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        solve(0,candidates,target,temp,ans,n);
        return ans;
    }
};
