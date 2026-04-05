class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        int m=edges.size();
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> pq;
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                pq.push(i);
                vis[i]=1;
                count++;
                while(!pq.empty()){
                    auto it=pq.front();
                    pq.pop();
                    for(auto ij: adj[it]){
                        if(!vis[ij]){
                            vis[ij]=1;
                            pq.push(ij);
                        }
                    }
                }
            }
        }
        return count;

    }
};
