#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Queue{
  private:
    int front,rear,capacity;
    int* queue;
    
  public:
    
    Queue(int c){
        front=0;
        rear=0;
        capacity=c;
        queue = new int;
    }
    
    void enqueue(int x){
        if(capacity==rear){
            cout<<"Queue is Full\n";
            return;
        }
        queue[rear++]=x;
    }
    
    int dequeue(){
        if(front==rear){
            cout<<"Queue is Empty\n";
            return -1;
        }
        int res = queue[front];
        for(int i=0;i<rear-1;i++){
            queue[i]=queue[i+1];
        }
        rear--;
        return res;
    }
    
    int peek(){
        if(front==rear){
            cout<<"Queue is Empty\n";
            return -1;
        }
        return queue[front];
    }
    
    void queueDisplay(){
        if(front==rear){
            cout<<"Queue is Empty\n";
        }
        for(int i=front;i<rear;i++){
            cout<<queue[i]<<" ";
        }
    }

};

int main(){
    Queue q(10);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(2);
    q.enqueue(10);;
    cout<<"front: "<<q.peek()<<"\n";
    cout<<"popped: "<<q.dequeue()<<"\n";
    q.queueDisplay();
    
}
