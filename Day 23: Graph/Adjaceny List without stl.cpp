#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val,weight;
    Node* next;
};

struct Edges {
    int src,dest,weight;
};

class Graph {
    Node* getAdjListNode(Node* head,int dest,int weight){
        Node *newNode = new Node();
        newNode->val = dest;
        newNode->weight = weight;
        newNode->next = head;
        return newNode;
    }
    
    int N;
public:
    Node **head;
    
    Graph(Edges edges[],int n,int m){
        this->N = n;
        head = new Node*[N+1]();
        for(int i=0;i<=N;i++) head[i]=NULL;
        for(int i=0;i<m;i++){
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;
            Node *newNode = getAdjListNode(head[src],dest,weight);
            head[src]=newNode;
        }
    }
    
    ~Graph(){
        for(int i=0;i<=N;i++){
            delete[] head[i];
            delete[] head;
        }
    }
    
    void printNodes(Node * head, int i){
        while(head!=NULL){
            cout << "(" << i << ", " << head->val
            << ", " << head->weight << ") ";
            head = head->next;
        }
        cout<<"\n";
    }
};

int main(){
    Edges edges[] = {
        {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
    int n = 5;
    int m = sizeof(edges)/sizeof(edges[0]);
    Graph g(edges,n,m);
    for (int i = 0; i <= n; i++)
    {
        // display adjacent vertices of vertex i
        g.printNodes(g.head[i], i);
    }
    
}
