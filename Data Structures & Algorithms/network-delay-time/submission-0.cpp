class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> vk(n+1);
        for(auto& it: times){
            int x=it[0],y=it[1],t=it[2];
            vk[x].push_back({y,t});
        }
        vector<int> vis(n+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        int maxi=0;
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int time=it.first;
            pq.pop();
            if(vis[node]==1){
                continue;
            }
            maxi=max(maxi,time);
            vis[node]=1;
            for(auto i: vk[node]){
             //   cout<<i.first<<' ';
                if(vis[i.first]==0){
                    pq.push({i.second+time,i.first});
                }
            }

            
        }
        int livable=true;
        for(int i=1;i<n+1;i++){
            if(vis[i]==0){
                livable=false;
                break;
            }
        }
        //cout<<maxi;
        return livable?maxi:-1;

    }
};
