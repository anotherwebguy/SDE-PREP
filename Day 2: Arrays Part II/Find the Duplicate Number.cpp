class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};

/*
  O(N)-time
  O(1)-space
*/


/////////////////////////////////// java Solution /////////////////////////////////////////////////
public class Solution {
    // DO NOT MODIFY THE ARGUMENTS WITH "final" PREFIX. IT IS READ ONLY
    public int[] repeatedNumber(final int[] A) {
        int x = 0, y = 0,ans=0;
        for(int i: A) ans^=i;
        for(int i=1;i<=A.length;i++) ans^=i;
        int setloc = ans & ~(ans-1);
        for(int i:A){
            if((i&setloc)!=0) x^=i;
            else y^=i;
        }
        for(int i=1;i<=A.length;i++){
            if((i&setloc)!=0) x^=i;
            else y^=i;
        }
        for(int i:A) if(i==x) return new int[] {x,y};
        return new int[] {y,x};
    }
}
