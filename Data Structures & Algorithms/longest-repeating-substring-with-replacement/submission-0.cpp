class Solution {
public:
    int characterReplacement(string s, int k) {
      int n=s.length();
      int i=0,j=0,count=0,maxi=0;
      vector<int> vk(26,0);
      while(j<n){
         vk[s[j]-'A']++;
         int max_here=*max_element(vk.begin(),vk.end());
         if((j-i+1)-max_here<=k && j-i+1>count){
            count=max(count,j-i+1);
         }
         if(j-i+1-max_here>k){
            while(j-i+1-*max_element(vk.begin(),vk.end())>k){
                vk[s[i]-'A']--;
                i++;
            }
         }
         j++;

      }
      return count;
    }
};
