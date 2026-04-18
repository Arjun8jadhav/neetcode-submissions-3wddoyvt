class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> vk;
        vk.push({0,{src,0}});
        vector<int> ans(n,1e9);
        while(!vk.empty()){
            auto it=vk.top();
            int steps=it.first;
            int dest=it.second.first;
            int cost=it.second.second;
            vk.pop();
            if(steps>k){
                continue;
            }
            
            for(auto i: adj[dest]){
                if(i.second+cost<ans[i.first] && steps<=k){
                    ans[i.first]=i.second+cost;
                    vk.push({steps+1,{i.first,i.second+cost}});
                }
            }
        }
        return ans[dst]==1e9?-1:ans[dst];


    }
};