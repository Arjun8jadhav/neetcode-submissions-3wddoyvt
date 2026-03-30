class TimeMap {
public:
    string binarySearch(string s,int time){
        int i=0,j=vk[s].size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(vk[s][mid].first==time){
                return vk[s][mid].second;
            }
            else if(vk[s][mid].first>=time){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return vk[s][j].second;
    }
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
        return binarySearch(key,timestamp);
    }
};
