/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
#include<bits/stdc++.h>
int findCelebrity(int n) {
 	// Write your code here.
    stack<int> s;
    for(int i=0;i<n;i++) s.push(i);
    while(s.size()>1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(knows(a,b)) s.push(b);
        else s.push(a);
    }
    int c = s.top();
    if(s.empty()) return -1;
    for(int i=0;i<n;i++){
        if(i!=c && !knows(i,c)) return -1;
        if(knows(c,i)) return -1;
    }
    return c;
}

//O(N)-time and space
