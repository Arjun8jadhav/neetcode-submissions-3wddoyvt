class Solution {
public:
    bool check_(string a,string b){
        int count=0;
        int n=a.length();
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                count++;
            }
        }
        return count==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        string start=beginWord;
        bool curable=false;
        unordered_map<string,vector<string>> vk;
        for(auto it: wordList){
            if(check_(start,it)){
                vk[start].push_back(it);
            }
        }
        int n=wordList.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check_(wordList[i],wordList[j])){
                    vk[wordList[i]].push_back(wordList[j]);
                    vk[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        queue<string> pq;
        pq.push(start);
        unordered_set<string> tp;
        tp.insert(start);
        int count=0;
        while(!pq.empty()){
            int size=pq.size();
            count++;
            cout<<count<<endl;
            for(int i=0;i<size;i++){
                auto it=pq.front();
                pq.pop();
                if(it==endWord){
                    return count;
                }
                for(auto tt: vk[it]){
                    if(!tp.count(tt)){
                    tp.insert(tt);
                    pq.push(tt);
                     }
                }
            }

            
        }
        return 0;
        
    }
};
