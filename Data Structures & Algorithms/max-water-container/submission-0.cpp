class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi=0,i=0,j=heights.size()-1;
        while(i<j){
            int mini=min(heights[i],heights[j]);
            maxi=max(maxi,mini*(j-i));
            if(heights[i]>=heights[j]){
                 j--;
            }
            else{
                i++;
            }
        }
        return maxi;
    }
};
