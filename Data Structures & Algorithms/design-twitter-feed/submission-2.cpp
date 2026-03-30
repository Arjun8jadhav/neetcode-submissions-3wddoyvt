class Twitter {
public:
    unordered_map<int,unordered_set<int>> follow_list;
    unordered_map<int,vector<pair<int,int>>> post_;
    int time=0;
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        post_[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,vector<int>>> pq;
        int n=post_[userId].size()-1;
        if(n>=0){
           pq.push({post_[userId][n].first,{userId,post_[userId][n].second,n}});
        }
        for(auto& it: follow_list[userId]){
             int len=post_[it].size()-1;
             if(len>=0){
                  pq.push({post_[it][len].first,{it,post_[it][len].second,len}});
             }
        }
        int limit=10;
        while(!pq.empty() && limit){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second[1]);
            if(it.second[2]-1>=0){
               pq.push({post_[it.second[0]][it.second[2]-1].first,{
                it.second[0], post_[it.second[0]][it.second[2]-1].second,it.second[2]-1
            }});
            }
            limit--;
        }
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
           follow_list[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(follow_list.count(followerId) && follow_list[followerId].count(followeeId)){
              follow_list[followerId].erase(followeeId);
        }
        
    }
};
