// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], int left,int mid, int right){
        int i = left, j = mid, k = 0;
          long long int invCount = 0;
          int temp[(right - left + 1)];
         
          while ((i < mid) && (j <= right)) {
            if (arr[i] <= arr[j]) {
              temp[k] = arr[i];
              ++k;
              ++i;
            } else {
              temp[k] = arr[j];
              invCount += (mid - i);
              ++k;
              ++j;
            }
          }
         
          while (i < mid) {
            temp[k] = arr[i];
            ++k;
            ++i;
          }
         
          while (j <= right) {
            temp[k] = arr[j];
            ++k;
            ++j;
          }
         
          for (i = left, k = 0; i <= right; i++, k++) {
            arr[i] = temp[k];
          }
         
          return invCount;

        
    }
    long long int mergeSort(long long arr[], int left, int right){
      long long int invCount = 0;
 
      if (right > left) {
        int mid = left + (right-left) / 2;
        invCount = mergeSort(arr, left, mid);
        invCount += mergeSort(arr, mid + 1, right);
        invCount += merge(arr, left, mid + 1, right);
      }
      return invCount;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int ans = mergeSort(arr,0,N-1);
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
