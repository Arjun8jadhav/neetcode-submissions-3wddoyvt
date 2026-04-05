class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        if(n-1!=m){
            return false;
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> pq;
        pq.push(0);
        vector<int> vis(n,0);
        vis[0]=1;
        int count=1;
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            for(auto i: adj[it]){
                if(vis[i]==0){
                    vis[i]=1;
                    pq.push(i);
                    count++;
                }
            }
        }
        return count==n;
        

    }
};
