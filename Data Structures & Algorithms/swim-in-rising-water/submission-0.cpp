class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> vk;
        vk.push({grid[0][0],0});
        vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
        while(!vk.empty()){
            auto it=vk.top();
            vk.pop();
            int pt=it.first;
            int x=it.second/m;
            int y=it.second%m;
            if(vis[x][y]==1){
                continue;
            }
            if(x==n-1 && y==m-1){
                return pt;
            }
            vis[x][y]=1;
            for(auto &i: dirs){
                int x_=x+i.first;
                int y_=y+i.second;
                if(x_>=0 && y_>=0 && x_<n && y_<m && vis[x_][y_]==0){
                    vk.push({max(pt,grid[x_][y_]),x_*m+y_});
                }
            }



        }
        return -1;

    }
};
