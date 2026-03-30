class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0,n=s.length();
        unordered_map<char,int> vk;
        int ans=INT_MAX;
        int fin=-1;
        for(auto& it: t){
            vk[it]++;
        }
        int count=vk.size();
        while(j<n){
            char c=s[j];
            if(vk.count(c)){
                vk[c]--;
                if(vk[c]==0){
                    count--;
                }
            }
            j++;
            while(count==0){
                if(j-i<ans){
                   ans=j-i;
                   fin=i;
                }
                if(vk.count(s[i])){
                    vk[s[i]]++;
                    if(vk[s[i]]==1){
                       count++;
                    }
                }
                i++;
            }
        }
        
        return fin==-1?"":s.substr(fin,ans);
    }
};
