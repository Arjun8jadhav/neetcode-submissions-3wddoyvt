class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,n=s.length();
        int ans=0;
        unordered_map<char,int> vk;
        while(j<n){
           int num=s[j]-'a';
           vk[num]++;
           if(vk[num]==2){
              ans=max(ans,j-i);
              while(vk[num]==2){
                 vk[s[i]-'a']--;
                 i++;
              }
           }
           j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};
