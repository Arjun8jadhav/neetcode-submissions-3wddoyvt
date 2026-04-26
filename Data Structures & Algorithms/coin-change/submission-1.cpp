class Solution {
public:
    long long solve(int idx,vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(amount==0){
            return 0;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        if(idx>=coins.size()){
            return INT_MAX;
        }
        long long ans=INT_MAX;
        for(int i=0;coins[idx]*i<=amount;i++){
            ans=min(ans,i+solve(idx+1,coins,amount-coins[idx]*i,dp));
        }
        return dp[idx][amount]= ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(10001,-1));
        long long result=solve(0,coins,amount,dp);
        return result==INT_MAX?-1:result;
    }
};
