class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> vk;
        for(auto & it: stones){
            vk.push(it);
        }
      
        while(vk.size()>=2){
            int first=vk.top();
            vk.pop();
            int second=vk.top();
            vk.pop();
            if(first!=second){
                vk.push(abs(first-second));
            }
            
        }
        return !vk.empty()?vk.top():0;
    }
};
