class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            int left=i,right=i;
            while(left>=0 && right<n){
                if(s[left]!=s[right]){
                    break;
                }
                ans++;
                left--;
                right++;
            }
            int l1=i-1,r1=i;
            while(l1>=0 && r1<n){
                if(s[l1]!=s[r1]){
                    break;

                }
                ans++;
                l1--;
                r1++;
            }
        }
        return ans;
    }
};
