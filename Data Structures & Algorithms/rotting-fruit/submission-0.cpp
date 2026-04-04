class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> vk;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                   vk.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        int count=0;
        int dirx[4]={1,0,-1,0};
        int diry[4]={0,1,0,-1};
        while(!vk.empty()){
            int size=vk.size();
            int foundFresh=0;
            for(int i=0;i<size;i++){
                auto it=vk.front();
                vk.pop();
                int idx=it.first,idy=it.second;
                for(int i=0;i<4;i++){
                    int x=idx+dirx[i];
                    int y=idy+diry[i];
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                        foundFresh++;
                        grid[x][y]=2;
                        vk.push({x,y});
                    }
                }
            }
            if(foundFresh){
                fresh-=foundFresh;
                count++;
            }
        }
        cout<<fresh;
        return fresh==0?count:-1;
    }
};
