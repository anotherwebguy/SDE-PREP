#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack{
  private:
    int top;
    int a[MAX];
    
  public:
    void push(int x){
        if(top>=(MAX-1)){
            cout<<"Stack is full\n";
            return ;
        }
        a[++top]=x;
    }
    
    int pop(){
        if(isEmpty()){
            cout<<"Stack is Empty\n";
            return -1;
        }
        return a[top--];
    }
    
    int peek(){
        if(isEmpty()){
            cout<<"Stack is Empty\n";
            return -1;
        }
        return a[top];
    }

    Stack(){
        top=-1;
    }
    
    bool isEmpty(){
        return top<0;
    }

};

int main(){
    Stack s;
    s.push(3);
    s.push(5);
    s.push(2);
    cout<<"peek: "<<s.peek()<<"\n";
    cout<<"popped: "<<s.pop()<<"\n";
    while(!s.isEmpty()){
        cout<<s.pop()<<" ";
    }
    
}
