class Solution {
public:
    bool isValid(string s) {
        stack<char> vk;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                vk.push(s[i]);
            }
            else if(vk.empty()){
                return false;
            }
            else if(s[i]==')' && vk.top()=='('){
                  vk.pop();
            }
            else if(s[i]=='}' && vk.top()=='{'){
                  vk.pop();
            }
            else if(s[i]==']' && vk.top()=='['){
                  vk.pop();
            }
            else{
                return false;
            }

        }
        return vk.size()==0;
    }
};
