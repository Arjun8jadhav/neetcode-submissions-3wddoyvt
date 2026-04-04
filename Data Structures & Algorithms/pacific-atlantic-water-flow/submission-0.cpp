class Solution {
public:
    int n,m;
    void bfs(queue<pair<int,int>>& pq,vector<vector<bool>>& pa,
            vector<vector<int>>& heights){
        int dirx[4]={0,1,0,-1};
        int diry[4]={1,0,-1,0};
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            int idx=it.first,idy=it.second;
            for(int i=0;i<4;i++){
                int x=idx+dirx[i];
                int y=idy+diry[i];
                if(x>=0 && x<n && y>=0 && y<m && heights[x][y]>=heights[idx][idy] && !pa[x][y]){
                    pa[x][y]=true;
                    pq.push({x,y});
                }
            }

        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size(),m=heights[0].size();
        vector<vector<bool>> pac(n,vector<bool>(m,false));
        vector<vector<bool>> alt(n,vector<bool>(m,false));
        vector<vector<int>> ans;
        queue<pair<int,int>> pa,al;
        for(int i=0;i<n;i++){
            pac[i][0]=true;
            pa.push({i,0});
            alt[i][m-1]=true;
            al.push({i,m-1});
        }
        for(int i=0;i<m;i++){
            alt[n-1][i]=true;
            al.push({n-1,i});
            pac[0][i]=true;
            pa.push({0,i});
        }
        bfs(al,alt,heights);
        bfs(pa,pac,heights);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && alt[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;


    }
};
