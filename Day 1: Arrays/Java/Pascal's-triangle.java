class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        for(int i=0;i<numRows;i++){
            List<Integer> row = new ArrayList<>();
            if(i==0){
                row.add(1);
                res.add(row);
                continue;
            }
            List<Integer> lastrow = res.get(i-1);
            row.add(1);
            for(int j=0;j<lastrow.size()-1;j++){
                row.add(lastrow.get(j)+lastrow.get(j+1));
            }
            row.add(1);
            res.add(row);
        }
        return res;
    }
}


//O(n^2) time
//O(n) space
