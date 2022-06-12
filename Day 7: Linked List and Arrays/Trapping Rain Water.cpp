class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax=0,rightmax=0,l=0,r=height.size()-1;
        int res=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>leftmax) leftmax=height[l];
                else res+=leftmax-height[l];
                l++;
            } else {
                if(height[r]>rightmax) rightmax=height[r];
                else res+=rightmax-height[r];
                r--;
            }
        }
        return res;
    }
};

//O(N)-time
//O(1)-space
