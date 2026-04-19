class Solution {
public:
    int solve(int step,int n,vector<int>& vk){
       if(step==n){
         return 1;
       }
       if(step>n){
         return 0;
       }
       if(vk[step]!=-1){
        return vk[step];
       }
       return vk[step]=solve(step+1,n,vk)+solve(step+2,n,vk);
    }
    int climbStairs(int n) {
        vector<int> vk(n+1,-1);
        return solve(0,n,vk);
    }
};
