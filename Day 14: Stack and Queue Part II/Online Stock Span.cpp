class StockSpanner {
    int index=0;
    stack<pair<int,int>> s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!s.empty() && s.top().first<=price) s.pop();
        if(s.empty()){
            s.push({price,index++});
            return s.top().second+1;
        } else {
            int val = index-s.top().second;
            s.push({price,index++});
            return val;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 * O(N)-time
 * O(N)-space
 */
