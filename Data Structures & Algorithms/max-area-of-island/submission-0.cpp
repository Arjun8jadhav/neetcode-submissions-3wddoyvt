class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i<0 || i==n || j<0 || j==m || grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        return 1+solve(i+1,j,n,m,grid)+solve(i,j+1,n,m,grid)+solve(i-1,j,n,m,grid)+solve(i,j-1,n,m,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxi=max(maxi,solve(i,j,n,m,grid));
                }
            }
        }
        return maxi;
    }
};
