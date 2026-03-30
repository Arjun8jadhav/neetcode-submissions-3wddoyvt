class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int  i=0,j=0;
        int n=nums1.size(),m=nums2.size();
        vector<double> vk;
        while(i<n && j<m){
            if(nums1[i]>=nums2[j]){
                 vk.push_back(nums2[j]);
                 j++;
            }
            else{
                vk.push_back(nums1[i]);
                i++;
            }
        }
        while(i<n){
            vk.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            vk.push_back(nums2[j]);
            j++;
        }
        if((n+m)%2==0){
            return (vk[(n+m)/2]+vk[((n+m)/2)-1])/2;
        }
        return vk[(n+m)/2];
    }
};
