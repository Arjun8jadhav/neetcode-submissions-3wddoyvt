class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j){
            int tot=nums[i]+nums[j];
            if(nums[i]==nums[j]){
                return {-1,-1};
            }
            if(tot==target){
                return {i+1,j+1};
            }
            else if(tot>target){
                    j--;
            }
            else{
                i++;
            }
        }
    }
};
            