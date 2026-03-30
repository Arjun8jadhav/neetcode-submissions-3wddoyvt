class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=0,n=nums.size();
        int mini=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]>mini){
                ans=max(ans,nums[i]-mini);

            }
            else{
                mini=nums[i];
            }
        }
        return ans;
    }
};
