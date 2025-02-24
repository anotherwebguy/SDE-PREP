class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length, m = matrix[0].length;
        int l = 0, h = (m*n)-1;
        int t = Math.max(m,n);
        while(l<=h){
            int mid = l+((h-l)>>1);
            int x = mid/m, y = mid%m;
            if(matrix[x][y]==target) return true;
            else if(matrix[x][y]>target) h = mid-1;
            else l = mid+1;
        }
        return false;
    }
}

//O(NlogN) time
