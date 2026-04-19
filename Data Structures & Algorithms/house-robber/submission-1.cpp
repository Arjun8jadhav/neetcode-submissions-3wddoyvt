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
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[n-1]=nums[n-1];
        for(int i=n-1;i>=0;i--){
            int take=nums[i]+(i+2>=n?0:dp[i+2]);
            int not_take=(i+1>=n?0:dp[i+1]);
            dp[i]=max(take,not_take);
        }
        return dp[0];
        
    }
};
