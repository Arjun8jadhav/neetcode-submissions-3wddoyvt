class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxi=0;
        string str="";
        for(int i=0;i<n;i++){
            int left=i-1,right=i+1;
            while(left>=0 && right<n){
                if(s[left]!=s[right]){
                    break;
                }
                left--;
                right++;
            }
            left++;
            right--;
            int len=(right-left+1);
            if(len>maxi){
                maxi=len;
                str=s.substr(left,len);
            }
            int l1=i-1,r1=i;
            while(l1>=0 && r1<n){
                if(s[l1]!=s[r1]){
                    break;

                }
                l1--;
                r1++;
            }
            l1++;
            r1--;
            len=r1-l1+1;
            if(len>maxi){
                maxi=len;
                str=s.substr(l1,len);
            }
        }
        return str;
    }
};
