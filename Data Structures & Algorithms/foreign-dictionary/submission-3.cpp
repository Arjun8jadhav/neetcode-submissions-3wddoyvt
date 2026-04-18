class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> vis(26,0);
        vector<vector<int>> adj(26);
        int n=words.size();
        for(auto it: words){
            for(auto ij: it){
                vis[ij-'a']=1;
            }
        }
        for(int j=1;j<n;j++){
            string a=words[j-1];
            string b=words[j];
            int i=0;
            int len1=a.length(),len2=b.length();
            if(len1 > len2 && a.substr(0, len2) == b){
               return "";
            }
            while(i<len1 && i<len2){
                if(a[i]!=b[i]){
                    adj[a[i]-'a'].push_back(b[i]-'a');
                    break;
                }
                i++;
            }

        }
        vector<int> outgoing(26,0);
        for(int i=0;i<26;i++){
            if(vis[i]==1){
                for(auto it: adj[i]){
                    outgoing[it]++;
                }
            }
        }
        queue<int> pq;
        for(int i=0;i<26;i++){
            if(vis[i] && outgoing[i]==0){
                pq.push(i);
            }
        }
        string str="";
        while(!pq.empty()){
            auto it=pq.front();
            str+=(it+'a');
            vis[it]=0;
            pq.pop();
            for(auto ij: adj[it]){
                outgoing[ij]--;
                if(outgoing[ij]==0){
                    pq.push(ij);
                }
            }
        }
        for(int i=0;i<26;i++){
            if(vis[i]==1){
                return "";
            }
        }
       // reverse(str.begin(),str.end());
        return str;
    }
};
