class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,greater<int>> vk;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            vk.push(nums[i]);
            count++;
            if(count>k){
                vk.pop();
                count--;
            }
            
        }
        return vk.top();
    }
};
