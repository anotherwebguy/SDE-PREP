#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
  private:
    vector<int> arr;
    
    int Parent(int i){
        return (i-1)/2;
    }
    
    int Left(int i){
        return 2*i+1;
    }
    
    int Right(int i){
        return 2*i+2;
    }
    
    //heapify down that is top to down
    void heapify_down(int i){
        int left = Left(i);
        int right = Right(i);
        int largest = i;
        if(left<size() && arr[left]>arr[largest]) largest=left;
        if(right<size() && arr[right]>arr[largest]) largest=right;
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify_down(largest);
        }
    }
    
    //heapify up that is down to up
    void heapify_up(int i){
        if(i && arr[Parent(i)]<arr[i]){
            swap(arr[Parent(i)],arr[i]);
            heapify_up(Parent(i));
        }
    }
    
  public:
    int size(){
        return arr.size();
    }
    
    void push(int x){
        arr.push_back(x);
        heapify_up(size()-1);
    }
    
    void pop(){
        if(size()==0) {
            cout<<"Priority queue empty";
            return;
        }
        arr[0]=arr[size()-1];
        arr.pop_back();
        heapify_down(0);
    }
    
    int top(){
        if(size()==0) {
            cout<<"Priority queue empty";
            return -1;
        }
        return arr[0];
    }
};

int main(){
    MaxHeap pq;
    pq.push(3);
    pq.push(2);
    pq.push(15);
 
    cout << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    pq.push(5);
    pq.push(4);
    pq.push(45);
 
    cout << endl << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    pq.top();    // top operation on an empty heap
    pq.pop();    // pop operation on an empty heap
 
    return 0;
}


//O(nlogn)
