class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=height.size()-1;
        int leftmax=0,rightmax=0;
        int count=0;
        while(i<j){
            if(height[i]<=height[j]){
                if(height[i]>=leftmax){
                    leftmax=height[i];
                }
                else{
                   count+=(leftmax-height[i]);
                 //  cout<<count<<" "<<i<<endl;
                }
                i++;
            }
            else{
                if(height[j]>=rightmax){
                    rightmax=height[j];
                }
                else{
                    count+=(rightmax-height[j]);
                  //  cout<<count<<' '<<j<<endl;
                }
                j--;
            }
        }
        return count;
    }
};
