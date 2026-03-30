class Solution {
public:
    bool check(int mid,vector<int>& piles, int h) {
        int counthr=0;
        for(auto it: piles){
            counthr+=(it/mid);
            if(it%mid!=0){
                counthr++;
            }
        }
        return counthr<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,piles,h)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
