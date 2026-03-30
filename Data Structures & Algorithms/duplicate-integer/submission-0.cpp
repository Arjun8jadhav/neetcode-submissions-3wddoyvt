class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> vk;
        int n=nums.size();
        for(int i=0;i<n;i++){
            vk[nums[i]]++;
            if(vk[nums[i]]>1){
                return true;
            }
        }
        return false;
    }
};