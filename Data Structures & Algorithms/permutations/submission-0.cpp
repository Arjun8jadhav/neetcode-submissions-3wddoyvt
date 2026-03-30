class Solution {
public:
    void solve(vector<int>& nums,vector<int>& temp,
    vector<vector<int>>& ans,int n,vector<int>& vis){
        bool should=true;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                should=false;
                temp.push_back(nums[i]);
                vis[i]=1;
                solve(nums,temp,ans,n,vis);
                vis[i]=0;
                temp.pop_back();
            }
            
        }
        if(should){
            ans.push_back(temp);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int> vis(n,0);
        vector<int> temp;
        solve(nums,temp,ans,n,vis);
        return ans;
    }
};
