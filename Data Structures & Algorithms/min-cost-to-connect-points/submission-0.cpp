class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> vis(n,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> vk;
        int cost=0;
        vk.push({0,0});
        while(!vk.empty()){
            auto it=vk.top();
            vk.pop();
            int cost_=it.first;
            int idx=it.second;
            if(vis[idx]==1){
                continue;
            }
            vis[idx]=1;
            cost+=cost_;
            int x1=points[idx][0];
            int y1=points[idx][1];
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int x2=points[i][0];
                    int y2=points[i][1];
                    vk.push({abs(x1-x2)+abs(y1-y2),i});
                }
            }
            
        }
        return cost;
    }
};
