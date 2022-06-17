
// Java program to demonstrate the 
// working of ArrayList in Java 
  
import java.io.*; 
import java.util.*;

class MinHeap {
    private ArrayList<Integer> arr;
    
    MinHeap(){
        arr = new ArrayList<>();
    }
    
    private int Parent(int i){
        return (i-1)/2;
    }
    
    private int Left(int i){
        return 2*i+1;
    }
    
    private int Right(int i){
        return 2*i+2;
    }
    
    private void swap(int i, int j)
    {
        int tmp;
        tmp = arr.get(i);
        arr.set(i,arr.get(j));
        arr.set(j,tmp);
    }
    
    //heapify down that is top to down
    private void heapify_down(int i){
        int left = Left(i);
        int right = Right(i);
        int smallest = i;
        if(left<size() && arr.get(left)<arr.get(smallest)) smallest=left;
        if(right<size() && arr.get(right)<arr.get(smallest)) smallest=right;
        if(smallest!=i){
            swap(smallest,i);
            heapify_down(smallest);
        }
    }
    
    //heapify up that is down to up
    private void heapify_up(int i){
        if(i>0 && arr.get(Parent(i))>arr.get(i)){
            swap(Parent(i),i);
            heapify_up(Parent(i));
        }
    }
    
    public int size(){
        return arr.size();
    }
    
    public void push(int x){
        arr.add(x);
        heapify_up(size()-1);
    }
    
    public void pop(){
        if(size()==0) {
            System.out.println("Priority queue empty");
            return;
        }
        arr.set(0,arr.get(size()-1));
        arr.remove(size()-1);
        heapify_down(0);
    }
    
    public int top(){
        if(size()==0) {
            System.out.println("Priority queue empty");
            return -1;
        }
        return arr.get(0);
    }
}

public class Main
{
	public static void main(String[] args) {
	    MinHeap pq = new MinHeap();
        pq.push(3);
        pq.push(2);
        pq.push(15);
     
        System.out.println("Size is "+ pq.size() );
     
        System.out.print( pq.top() +" ");
        pq.pop();
     
        System.out.print( pq.top() +" ");
        pq.pop();
     
        pq.push(5);
        pq.push(4);
        pq.push(45);
     
        System.out.println("Size is "+ pq.size() );
     
        System.out.print( pq.top() +" ");
        pq.pop();
     
        System.out.print( pq.top() +" ");
        pq.pop();
     
        System.out.print( pq.top() +" ");
        pq.pop();
     
        System.out.print( pq.top() +" ");
        pq.pop();
     
        pq.top();    // top operation on an empty heap
        pq.pop();    
	}
}
