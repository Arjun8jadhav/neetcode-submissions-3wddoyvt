class Solution {
public:
    int evalRPN(vector<string>& s) {
        int fin_num=0;
        int n=s.size();
        stack<int> vk;
        for(int i=0;i<n;i++){
            if(s[i]=="+" || s[i]=="-" || s[i]=="*" || s[i]=="/"){
                int s1=vk.top();
                vk.pop();
                int s2=vk.top();
                vk.pop();
                if(s[i]=="+"){
                    vk.push(s1+s2);
                } 
                else if(s[i]=="-"){
                    vk.push(s2-s1);
                }
                else if(s[i]=="*"){
                     vk.push(s1*s2);
                }
                else{
                    vk.push(s2/s1);
                }

            }
            else{
                vk.push(stoi(s[i]));
            }
        } 
        return vk.top();
    }
};
