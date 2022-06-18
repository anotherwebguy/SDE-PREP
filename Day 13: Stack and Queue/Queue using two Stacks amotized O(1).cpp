class MyQueue {
private:
    stack<int> s1,s2;
public:
    MyQueue() {
        
    }
    
    //O(1)
    void push(int x) {
        s1.push(x);
    }
    
    //O(1) or O(N)
    int pop() {
        if(!s2.empty()){
            int x = s2.top();
            s2.pop();
            return x;
        } else {
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int x = s2.top();
            s2.pop();
            return x;
        }
    }
    
    //O(1) or O(N)
    int peek() {
       if(!s2.empty()){
            int x = s2.top();
            return x;
        } else {
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
           return s2.top();
        }
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
