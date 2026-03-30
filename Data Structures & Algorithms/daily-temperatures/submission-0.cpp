class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> vk(n,0);
        stack<int> dp;
        for(int i=n-1;i>=0;i--){
            while(!dp.empty() && temp[i]>=temp[dp.top()]){
                dp.pop();
            }
            if(!dp.empty()){
                vk[i]=(dp.top()-i);
            }
            dp.push(i);
            

        }
        return vk;
    }
};
