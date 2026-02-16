#include <iostream>
using namespace std;

class Node
{   
public:
    int value;
    Node *next;
    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *Head;
    Node *Tail;
    LinkedList()
    {
        Head = Tail = NULL;
    }
    void pushfront(int val){
        Node *newnode = new Node(val);
        if(Head==NULL){
            Head=Tail=newnode;
            return;
        }
        newnode->next = Head;
        Head = newnode;
    }
    void pushback(int val){
        Node *newnode = new Node(val);
        if(Head==NULL){
            Head = Tail = newnode;
            return;
        }
        Tail->next = newnode;
        Tail = newnode;
    }
    void popfront(){
        if(Head==NULL){
            return;
        }
        Node *temp = Head;
        Head = Head->next;
        delete temp;
    }
    void popback(){
        if(Head==NULL){
            return;
        }
        if(Head==Tail){
            popfront();
        }
        Node *temp = Head;
        while(temp->next != Tail){
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;
        Tail->next = NULL;
    }
    void insert(int val,int pos){
        if(pos<0){
            return;
        }
        if(pos==0){
            pushfront(val);
            return;
        }
        Node* temp = Head;
        for(int i=0;i<pos-1 && temp !=NULL;i++){
            temp = temp->next;
        }
        Node *newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
    }
    void print(){
        Node* temp = Head;
        while(temp!=NULL){
            cout<<temp->value<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
} ;
int main()
{
    LinkedList ll;
    ll.pushfront(5);
    ll.pushfront(7);
    ll.pushback(9);
    ll.pushback(11);
    ll.popfront();
    ll.popback();
    ll.insert(5,2);
    ll.print();
}