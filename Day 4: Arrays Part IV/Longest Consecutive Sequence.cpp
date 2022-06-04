class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> m;
        int n=nums.size();
        for(int z=0;z<n;z++)
        {
            m[nums[z]]=1;
        }
        int ans=0;
        for(int z=0;z<n;z++)
        {
            if(!m[nums[z]-1])
            {
                int k=nums[z];
                int temp=0;
                while(m[k])
                {
                    temp++;
                    k++;
                }
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};
