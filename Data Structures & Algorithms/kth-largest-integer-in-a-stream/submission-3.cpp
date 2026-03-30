class KthLargest {
    int kth=0;
    priority_queue<int,vector<int>,greater<int>> vk;
public:
    
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for(auto&i : nums){
            vk.push(i);
        }
        int n=vk.size();
        while(n>k){
            vk.pop();
            n--;
        }
        
    }
    
    int add(int val) {
        vk.push(val);
        if(vk.size()>kth){
            vk.pop();
        }
        return vk.top();
    }
};
