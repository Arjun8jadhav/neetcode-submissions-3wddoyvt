class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> vk;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(vk.find(target-nums[i])!=vk.end()){
                return {vk[target-nums[i]],i};
            }
            vk[nums[i]]=i;
        //    cout<<nums[i]<<vk[nums[i]]<<endl;
        }
        return {-1,-1};
    }
};
