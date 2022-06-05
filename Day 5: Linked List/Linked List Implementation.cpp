#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

void insertatbegin(Node** head,int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head);
    (*head)=new_node;
}

void insertafter(Node *prev, int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
}

void insertatend(Node** head,int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    Node *last = (*head);
    if(*head==NULL){
        *head = new_node;
        return;
    }
    while(last->next!=NULL){
        last = last->next;
    }
    last->next=new_node;
}

void print(Node **head){
    Node *last = *head;
    while(last!=NULL){
        cout<<last->data<<" ";
        last = last->next;
    }
}

void deleteNode(Node** head, int key){
    Node* last = *head;
    Node* prev = NULL;
    if(last!=NULL && last->data == key){
        *head = last->next;
        delete last;
        return;
    } else {
        while(last!=NULL && last->data!=key){
            prev = last;
            last = last->next;
        }
        if(last==NULL) return;
        prev->next = last->next;
        delete last;
    }
}


int main(){
    Node* head = new Node();
    insertatbegin(&head,5);
    insertatend(&head,7);
    insertatend(&head,10);
    insertatend(&head,4);
    insertatbegin(&head,2);
    insertafter(head->next,8);
    deleteNode(&head,5);
    print(&head);
}
