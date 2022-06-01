class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==1){
            res.push_back({1});
            return res;
        } 
        if(numRows==2){
            res.push_back({1});
            res.push_back({1,1});
            return res;
        }
        res.push_back({1});
        res.push_back({1,1});
        for(int i=2;i<numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=0;j<res.back().size()-1;j++){
                temp.push_back(res.back()[j]+res.back()[j+1]);
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};
