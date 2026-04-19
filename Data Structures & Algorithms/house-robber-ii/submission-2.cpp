class Solution {
public:
    int solve(int idx,vector<int>& nums,vector<int>& dp,int n){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take=nums[idx]+solve(idx+2,nums,dp,n);
        int not_take=solve(idx+1,nums,dp,n);
        return dp[idx]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n,-1),dp2(n,-1);
        return max(solve(0,nums,dp1,n-1),solve(1,nums,dp2,n));
        
        
    }
};
