class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<int,string>>> vk;
    void set(string key, string value, int timestamp) {
        vk[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!vk.count(key)){
            return "";
        }
        if(vk[key][0].first>timestamp){
            return "";
        }
        int n=vk[key].size();
        for(int i=0;i<n;i++){
            if(vk[key][i].first==timestamp){
                return vk[key][i].second;
            }
            if(vk[key][i].first>timestamp && i-1>=0){
                return vk[key][i-1].second;

            }
        }
        return vk[key][n-1].second;
    }
};
