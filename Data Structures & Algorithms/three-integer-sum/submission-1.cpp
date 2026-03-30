class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> vk;
        for(auto & i: nums){
            vk[i]++;
        }
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target=-1*(nums[i]+nums[j]);
                if(vk.find(target)!=vk.end()){
                    vk[nums[i]]--;
                    vk[nums[j]]--;
                    if(vk[target]>0 && target>=max(nums[i],nums[j])){
                        ans.push_back({nums[i],nums[j],target});
                    }
                    vk[nums[i]]++;
                    vk[nums[j]]++;

                }
                int curr=nums[j];
                while(j<n && nums[j]==curr){
                    j++;
                }
                j--;
                
            }
            int curr=nums[i];
            while(i<n && nums[i]==curr){
                i++;
            }
            i--;
        }
        return ans;
    }
};
