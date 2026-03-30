class Solution {
public:

    string encode(vector<string>& strs) {
        int n=strs.size();
        string encoded="";
        for(int i=0;i<n;i++){
             encoded+=(strs[i].length()+'0');
             encoded+=strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
          vector<string> vk;
          int i=0;
          int n=s.length();
          while(i<n){
              int len=s[i]-'0';
              i++;
              string temp="";
              while(i<n && len--){
                 temp+=s[i];
                 i++;
              }
              vk.push_back(temp);
          }
          return vk;
    }
};
