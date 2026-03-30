class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<pair<int,int>> vk;
        int maxArea=0;
        for(int i=0;i<n;i++){
            int start=i;
            while(!vk.empty() && vk.top().second>heights[i]){
                auto it=vk.top();
                vk.pop();
                maxArea=max(maxArea, it.second*(i-it.first));
                start=it.first;
            }
            vk.push({start,heights[i]});
        }
        while(!vk.empty()){
            auto it=vk.top();
            maxArea=max(maxArea,it.second*(n-it.first));
            vk.pop();
        }
        return maxArea;
    }
};
