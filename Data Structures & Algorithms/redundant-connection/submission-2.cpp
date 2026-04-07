
class disjoint{
    //vector<int> parent,rank,size;
    public:
    vector<int> parent,rank,sizeTotal;
    disjoint(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        sizeTotal.resize(n+1,1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findparent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findparent(parent[node]);
    }
    void unionbyrank(int u,int v){
        int u_parent=findparent(u);
        int v_parent=findparent(v);
        if(v_parent==u_parent){
            return;
        }
        if(rank[u_parent]>rank[v_parent]){
            parent[v_parent]=u_parent;
        }
        else if(rank[u_parent]<rank[v_parent]){
            parent[u_parent]=v_parent;
        }
        else{
            parent[u_parent]=v_parent;
            rank[v_parent]++;
        }

    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        disjoint s(n);
        for(auto& it: edges){
            int x=it[0],y=it[1];
            if(s.findparent(x)==s.findparent(y)){
                return it;
            }
            s.unionbyrank(x,y);

        }
        return {-1,-1};
    }


};