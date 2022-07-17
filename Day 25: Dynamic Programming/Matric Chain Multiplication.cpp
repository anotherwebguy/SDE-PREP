
class Solution{
public:
    int t[101][101];
    int helper(int arr[],int i,int j){
       if(i>=j) return 0;
       if(t[i][j]!=-1) return t
       [i][j];
       int ans=INT_MAX;
       for(int k=i;k<=j-1;k++){
           int tempans=helper(arr,i,k)+helper(arr,k+1,j)+(arr[i-1]*arr[j]*arr[k]);
           ans=min(ans,tempans);
        }
        return t[i][j]=ans;
      
   }
   
    int matrixMultiplication(int N, int arr[])
    {
        // code here
       memset(t, -1, sizeof(t));
       return helper(arr,1,N-1);
    }
};
