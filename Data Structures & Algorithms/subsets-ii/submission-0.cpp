class Solution {
public:
    void solve(int i,vector<int>& nums,vector<vector<int>> & ans,vector<int> temp,int & n){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
        
        int next_i=i;
        int count=0;
        while(next_i<n && nums[i]==nums[next_i]){
            next_i++;
            count++;
        }
        solve(next_i,nums,ans,temp,n);
        for(int j=1;j<=count;j++){
            temp.push_back(nums[i]);
            solve(next_i,nums,ans,temp,n);
        }
        for(int j=1;j<=count;j++){
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>  ans;
        vector<int> temp;
        int n=nums.size();
        solve(0,nums,ans,temp,n);
        return ans;
    }
};
