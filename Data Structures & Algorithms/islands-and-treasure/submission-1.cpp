class Solution {
public:
    // int bfs_search(int i,int j,int n,int m,vector<vector<int>>& grid){
    //     vector<vector<int>> vis(n,vector<int>(m,0));
    //     queue<vector<int>> vk;
    //     vk.push({i,j,0});
    //     vis[i][j]=1;
    //     while(!vk.empty()){
    //         auto it=vk.front();
    //         vk.pop();
    //         int idx=it[0];
    //         int idy=it[1];
    //         int count=it[2];
    //        // cout<<count<<endl;
    //         if(grid[idx][idy]==0){
    //             return count;
    //         }
    //         int dirx[4]={1,0,-1,0};
    //         int diry[4]={0,1,0,-1};
    //         for(int i=0;i<4;i++){
    //              int x=idx+dirx[i],y=idy+diry[i];
                 
    //              if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==0 && grid[x][y]!=-1){
    //                // cout<<x<<" "<<y<<" "<<idx<<" "<<idy<<endl;
    //                 vis[x][y]=1;
    //                 vector<int> temp={x,y,count+1};
    //                 vk.push(temp);
    //              }
    //         }
    //     }
    //     return grid[i][j];
    // }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>> vk;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    vk.push({i,j});
                }
            }
        }
        int dirx[4]={1,0,-1,0};
        int diry[4]={0,1,0,-1};
        while(!vk.empty()){
            auto it=vk.front();
            int idx=it.first,idy=it.second;
            vk.pop();
            for(int i=0;i<4;i++){
                int x=idx+dirx[i];
                int y=idy+diry[i];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==2147483647){
                    grid[x][y]=grid[idx][idy]+1;
                    vk.push({x,y});
                }
            }

        }
    }
};
