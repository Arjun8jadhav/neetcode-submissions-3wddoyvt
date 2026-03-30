class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> vk;
        vector<int> list1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!vk.empty() && vk.back()<=i-k){
                vk.pop_back();
            }
            while(!vk.empty() && nums[i]>=nums[vk.front()]){
             //   cout<<vk.back()<<" "<<i<<endl;
                vk.pop_front();
            }
            vk.push_front(i);
            if(i>=k-1){
                list1.push_back(nums[vk.back()]);
            }

        }
        return list1;
    }
};
