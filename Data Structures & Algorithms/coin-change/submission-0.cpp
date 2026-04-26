class Solution {
public:
    long long solve(int idx,vector<int>& coins,int amount){
        if(amount==0){
            return 0;
        }
        if(idx>=coins.size()){
            return INT_MAX;
        }
        long long ans=INT_MAX;
        for(int i=0;coins[idx]*i<=amount;i++){
            ans=min(ans,i+solve(idx+1,coins,amount-coins[idx]*i));
        }
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        long long result=solve(0,coins,amount);
        return result==INT_MAX?-1:result;
    }
};
