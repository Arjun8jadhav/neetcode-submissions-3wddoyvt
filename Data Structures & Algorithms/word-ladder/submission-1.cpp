class Solution {
public:
    int ladderLength(string begin, string endWord, vector<string>& word) {
        unordered_set<string> vk;
        for(int i=0;i<word.size();i++){
            vk.insert(word[i]);
        }
        queue<pair<string,int>> pq;
        pq.push({begin,1});
        if(vk.find(begin)!=vk.end()){
            vk.erase(begin);
        }
        while(!pq.empty()){
            string start=pq.front().first;
            int num=pq.front().second;
            pq.pop();
            for(int i=0;i<begin.size();i++){
               string dummy=start;
               for(int j=0;j<26;j++){
                   dummy[i]=j+'a';
                   if(vk.find(dummy)!=vk.end()){
                       if(dummy==endWord){
                           return num+1;
                       }
                       pq.push({dummy,num+1});
                       vk.erase(dummy);
                   }
               }
            }
        }
        return 0;

    }
};