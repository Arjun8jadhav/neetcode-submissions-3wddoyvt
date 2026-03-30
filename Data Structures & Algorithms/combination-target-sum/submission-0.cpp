class Solution {
public:
    void solve(int idx,vector<int>& nums, int target,vector<int>& temp,vector<vector<int>>& ans){
        if(idx>=nums.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(target<0){
            return;
        }
        solve(idx+1,nums,target,temp,ans);
        temp.push_back(nums[idx]);
        solve(idx,nums,target-nums[idx],temp,ans);
        temp.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums,target,temp,ans);
        return ans;
    }
};
