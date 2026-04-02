class PrefixTree {
    set<string> vk;
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        vk.insert(word);
    }
    
    bool search(string word) {
        return vk.count(word);
    }
    
    bool startsWith(string prefix) {
        int plen=prefix.length();
        for(auto &it: vk){
            int len=it.length();
            if(len>=plen){
                string check=it.substr(0,plen);
                if(prefix==check){
                    return true;
                }
            }
        }
        return false;
    }
};
