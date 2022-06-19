#include<bits/stdc++.h>

void sortStack(stack<int> &stk)
{
	// Write your code here
    stack<int> s1,s2;
    s1.push(stk.top());
    stk.pop();
    while(!stk.empty()){
        int x = stk.top();
        stk.pop();
        while(!s1.empty() && s1.top()>x){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    while(!s2.empty()){
        stk.push(s2.top());
        s2.pop();
    }
}

//O(2N)-time
//O(2N)-space
