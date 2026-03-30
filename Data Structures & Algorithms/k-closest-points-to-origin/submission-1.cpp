class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>> pq;
        int n=points.size();
        for(int i=0;i<n;i++){
             double tot=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
             cout<<tot<<endl;
             pq.push({tot,i});
             if(pq.size()>k){
               cout<<pq.top().first<<"dgdg"<<endl;
               pq.pop(); 
             }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
