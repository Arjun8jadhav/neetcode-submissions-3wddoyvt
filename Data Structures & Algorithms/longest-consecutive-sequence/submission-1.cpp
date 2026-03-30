class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int maxi=1;
        int prev=nums[0],count=1;
        for(int i=0;i<n;i++){
            if(prev==nums[i]){
                continue;
            }

            if(prev==nums[i]-1){
                count++;             
            }
            else{
                maxi=max(maxi,count);
                count=1;
            }
             prev=nums[i];

        }
        maxi=max(maxi,count);
        return maxi;

        
    }
};
