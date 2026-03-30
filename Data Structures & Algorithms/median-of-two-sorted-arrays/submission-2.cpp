class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size(),m=nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int tot=(n+m+1)/2;
        int i=0,j=n;
        while(i<=j){
            int mid=(i+(j-i)/2);
            int rem=tot-(mid);
            int l1=mid==0?INT_MIN:nums1[mid-1];
            int r1=mid>=n?INT_MAX:nums1[mid];
            int l2=rem==0?INT_MIN:nums2[rem-1];
            int r2=rem>=m?INT_MAX:nums2[rem];
            if(l1>r2){
                j=mid-1;
            }
            else if(r1<l2){
                i=mid+1;
            }
            else{
                if((n+m)%2==1){
                    return max(l1,l2);
                }
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
        }
        return -1;
    }
};
