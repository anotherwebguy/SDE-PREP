public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public ArrayList<Integer> repeatedNumber(final List<Integer> A) {
        int n = A.size();
        long sumN = (long) n * (n + 1) / 2;
        long sum2N = (long) n * (n + 1) * (2L * n + 1) / 6;
        
        long sumA = 0, sum2A = 0;
        for (int num : A) {
            sumA += num;
            sum2A += (long) num * num;
        }
        
        long diff = sumA - sumN; // X - Y
        long diff2 = sum2A - sum2N; // X^2 - Y^2 = (X - Y)(X + Y)
        
        long sumXY = diff2 / diff; // X + Y
        
        long X = (sumXY + diff) / 2;
        long Y = (sumXY - diff) / 2;
        
        ArrayList<Integer> result = new ArrayList<>();
        result.add((int) X);
        result.add((int) Y);
        return result;
    }
}

//O(N) time
