class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> vk(26,0);
        int count=0,n=s2.length();
        for(auto & it: s1){
            vk[it-'a']++;
            if(vk[it-'a']==1){
                count++;
            }
        }
        int i=0,j=0;
        while(j<n){
            vk[s2[j]-'a']--;
            if(vk[s2[j]-'a']>=0){
                if(vk[s2[j]-'a']==0){
                    count--;
                }
                if(count==0){
                    return true;
                }
            }
            while(vk[s2[j]-'a']<0){
                vk[s2[i]-'a']++;
                if(vk[s2[i]-'a']==1){
                    count++;
                }
                i++;
            }
            j++;
        }
        return false;

    }
};
