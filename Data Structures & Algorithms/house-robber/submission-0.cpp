class Solution {
public:
    int solve(int idx,vector<int>& nums,vector<int>& dp){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take=nums[idx]+solve(idx+2,nums,dp);
        int not_take=solve(idx+1,nums,dp);
        return dp[idx]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};
