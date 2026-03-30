class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int l=0,r=(n*m)-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int idx=mid/m;
            int idy=mid%m;
            cout<<mid<<endl;
            if(matrix[idx][idy]==target){
                return true;
            }
            else if(matrix[idx][idy]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return false;
    }
};
