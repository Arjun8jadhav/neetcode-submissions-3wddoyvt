class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vk(26,0);
        int n=s.length(),count=0;
        if(n!=t.length()){
            return false;
        }
        for(int i=0;i<n;i++){
            vk[s[i]-'a']++;
            if(vk[s[i]-'a']==1){
                count++;
            }
        }
        for(int i=0;i<n;i++){
            vk[t[i]-'a']--;
            if(vk[t[i]-'a']==0){
                count--;
            }
        }
        return count==0;
    }
};
