class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> vk;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(grid[0][i]=='O'){
                vk.push({0,i});
                vis[0][i]=1;
            }
            if(grid[n-1][i]=='O'){
                vk.push({n-1,i});
                vis[n-1][i]=1;
            }
        }
        for(int i=1;i<n-1;i++){
            if(grid[i][0]=='O'){
                vk.push({i,0});
                vis[i][0]=1;
            }
            if(grid[i][m-1]=='O'){
                vk.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
        while(!vk.empty()){
            auto it=vk.front();
            vk.pop();
            int idx=it.first,idy=it.second;
            for(auto it: dirs){
                int x=idx+it.first;
                int y=idy+it.second;
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='O' && vis[x][y]==0){
                    vis[x][y]=1;
                    vk.push({x,y});
                }
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
    }
};
