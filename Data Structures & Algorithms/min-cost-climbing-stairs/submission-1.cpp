class Solution {
public:
    int solve(int idx,vector<int>& cost,vector<int>& vk){
       if(idx>=cost.size()){
         return 0;
       }
       if(vk[idx]!=-1){
        return vk[idx];
       }
       return vk[idx]= cost[idx]+min(solve(idx+1,cost,vk),solve(idx+2,cost,vk));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> vk(cost.size()+1,-1);
        int start1=solve(0,cost,vk);
        int start2=solve(1,cost,vk);
        return min(start1,start2);
    }
};
