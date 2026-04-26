class Solution {
public:
    int solve(int i,int n,string s,vector<int>& vk){
        if(i>=n){
          return 1;
        }
        int total=0;
        if(s[i]=='0'){
            return 0;
        }
        if(vk[i]!=-1){
            return vk[i];
        }
        if(s[i]>'2' || i+1>=n){
            return vk[i]= solve(i+1,n,s,vk);
        }
        total+=solve(i+1,n,s,vk);
        if(s[i]<'2'){
            total+=solve(i+2,n,s,vk);
        }
        else if(s[i+1]<='6'){
            total+=solve(i+2,n,s,vk);
        }
        return vk[i]=total;


        
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int> vk(n+1,-1);
        return solve(0,n,s,vk);
    }
};
