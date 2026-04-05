class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        int m=pre.size();
        vector<vector<int>> vk(num);
        for(int i=0;i<m;i++){
            vk[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int> inDegree(num,0);
        for(int i=0;i<num;i++){
            for(auto it: vk[i]){
                 inDegree[it]++;
            }
        }
        queue<int> pq;
        for(int i=0;i<num;i++){
            if(inDegree[i]==0){
                pq.push(i);
            }
        }
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            for(auto it: vk[it]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    pq.push(it);
                }
            }
        }
        for(int i=0;i<num;i++){
            if(inDegree[i]>0){
                return false;
            }
        }
        return true;


        
    }
};
