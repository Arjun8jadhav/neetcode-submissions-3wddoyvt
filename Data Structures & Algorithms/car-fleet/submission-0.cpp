class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vk;
        int n=speed.size();
        for(int i=0;i<n;i++){
            vk.push_back({position[i],speed[i]});
        }
        sort(vk.rbegin(),vk.rend());
        stack<int> dp;
        for(int i=0;i<n;i++){
            if(dp.empty()){
                dp.push(i);
            }
            double l1=(target-vk[i].first)/(double)vk[i].second;
            double l2=(target-vk[dp.top()].first)/(double)vk[dp.top()].second;
            if(l2<l1){
               dp.push(i);
            }
        }
        return dp.size();
    }
};
