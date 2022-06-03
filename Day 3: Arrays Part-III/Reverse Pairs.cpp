class Solution {
public:
    int merge(vector<int> &nums,int &s,int &mid,int &e)
{
    int ans=0;
    int i=s,j=mid+1,k=0;

    for(i=s;i<=mid;i++)
    {
        while(j<=e&&2LL*nums[j]<nums[i])
        {
            j++;
        }
        ans+=j-(mid+1);
    }

    i=s;j=mid+1;
    vector<int> v(e-s+1);



    while(i<=mid&&j<=e)
    {
        if(nums[i]<nums[j])
        {
            v[k]=nums[i];
            i++;
        }
        else
        {
            v[k]=nums[j];
            j++;
        }
        k++;
    }

    while(i<=mid)
    {
        v[k]=nums[i];
        i++;k++;
    }
    while(j<=e)
    {
        v[k]=nums[j];
        k++;j++;
    }

    for(int z=0;z<e-s+1;z++)
    {
        nums[z+s]=v[z];
    }
    return ans;


}

void divide(vector<int> &nums,int s,int e,int &ans)
{

    if(s<e)
    {
        int mid=(s+e)/2;

        divide(nums,s,mid,ans);
        divide(nums,mid+1,e,ans);
        ans+=merge(nums,s,mid,e);

    }
}

int reversePairs(vector<int>& nums) {
    int ans=0;
    divide(nums,0,nums.size()-1,ans);

    return ans;

}
};


// O(NlogN)+2*O(N)-time
// O(N)-space
