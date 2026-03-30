class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int total=1;
         int n=nums.size();
         if(n==1){
            return {0};
         }
         vector<int> left(n,0),right(n,0);
         left[0]=nums[0];
         right[n-1]=nums[n-1];
         for(int i=1;i<n-1;i++){
            left[i]=nums[i]*left[i-1];
            right[n-1-i]=nums[n-1-i]*right[n-i];
         }
         vector<int> ans(n,0);
         ans[0]=right[1],ans[n-1]=left[n-2];
         for(int i=1;i<n-1;i++){
            ans[i]=left[i-1]*right[i+1];
         }
         return ans;
    }
};
