class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> vk;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(vk.find(nums[i])!=vk.end()){
                return true;
            }
            vk.insert(nums[i]);
        }
        return false;
    }
};