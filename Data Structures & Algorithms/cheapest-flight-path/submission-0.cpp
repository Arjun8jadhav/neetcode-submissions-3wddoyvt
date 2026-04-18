class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<int> vis(n,0);
        pq.push({0,src,0});
        while(!pq.empty()){
            auto [val, start, steps] = pq.top();
            pq.pop();
            vis[start]=1;
            if(start==dst){
                return val;
            }
            for(auto [dest,pr]: adj[start]){
                if(vis[dest]==0 && steps+1<=k+1){
                    pq.push({val+pr,dest,steps+1});
                }
            }
        }
        return -1;
        

    }
};
