import java.util.* ;
import java.io.*; 
public class Solution {
    public static long mergeSort(long arr[], int l, int r){
        long res = 0;
        if(l<r){
            int m = l + ((r - l) >> 1);
            res += mergeSort(arr,l,m);
            res += mergeSort(arr,m+1,r);
            res += merge(arr,l,m+1,r);
        }
        return res;
    }

    public static long merge(long arr[], int l, int m, int r){
        int i = l, j = m, k = 0;
        long res = 0;
        long temp[] = new long[r-l+1];
        while((i<m) && (j<=r)){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                res += (m-i);
            }
        }
        while(i<m){
            temp[k++] = arr[i++];
        }
        while(j<=r){
            temp[k++] = arr[j++];
        }
        for(i=l,k = 0;i<=r;i++, k++){
            arr[i] = temp[k];
        }
        return res;
    }

    public static long getInversions(long arr[], int n) {
        // Write your code here.
        long res = mergeSort(arr,0,n-1);
        return res;
    }
}

//O(NlogN) time
