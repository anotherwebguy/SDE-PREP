class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1,num2=-1,c1=0,c2=0;
        for(auto el:nums){
            if(el==num1) c1++;
            else if(el==num2) c2++;
            else if(c1==0){
                num1=el;
                c1=1;
            } else if(c2==0){
                num2=el;
                c2=1;
            } else {
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(auto el:nums){
            if(el==num1) c1++;
            else if(el==num2) c2++;
        }
        int n = nums.size();
        if(c1>n/3 && c2>n/3) return {num1,num2};
        else if(c1>n/3 && c2<=n/3) return {num1};
        else if(c1<=n/3 && c2>n/3) return {num2};
        else return {};
    }
};

// O(n)-time
// O(1)-space
