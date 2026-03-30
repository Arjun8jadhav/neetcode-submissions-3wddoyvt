class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map_(26,0);
        for(auto& it: tasks){
            map_[it-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
             if(map_[i]>0){
                pq.push(map_[i]);
             }
        }
        int time=0;
        queue<pair<int,int>> waiting;
        while(!pq.empty() || !waiting.empty()){
            time++;
            if(!pq.empty()){
                int top_=pq.top();
                pq.pop();
                if(top_-1>0){
                    waiting.push({top_-1,time+n});
                }
            }
            if(!waiting.empty() && waiting.front().second==time){
                auto it=waiting.front();
                waiting.pop();
                pq.push(it.first);

            }
        }
        return time;
    }
};
