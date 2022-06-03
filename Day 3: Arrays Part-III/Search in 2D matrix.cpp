class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int low = 0, high=(m*n)-1;
        while(low<=high){
            int mid = low+((high-low)>>1);
            int x = mid/n, y=mid%n;
            if(matrix[x][y]==target) return true;
            else if (matrix[x][y]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};

//  O(log(m*n))-time
//  O(1)-space
