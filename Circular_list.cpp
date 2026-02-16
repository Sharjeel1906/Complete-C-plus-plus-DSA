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
        next =  NULL;
    }
};
class CircularList
{
    Node *Head;
    Node *Tail;
public:
    CircularList()
    {
        Head = Tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (Head == NULL)
        {
            Head = Tail = newNode;
            Tail->next = Head; 
        }
        else
        {
            newNode->next = Head;
            Head = newNode;
            Tail->next  = Head;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (Head == NULL)
        {
            Head = Tail = newNode;
            Tail->next = Head;
        }
        else
        {
            newNode->next = Head;
            Tail->next= newNode;
            Tail = newNode;
        }
    }
    
    void pop_front(){
        if(Head==NULL){
            return;
        }else if(Head==Tail){
            delete Head;
            Head=Tail=NULL;
            }
        else{
            Node* temp = Head;
            Head = Head->next;
            Tail->next = Head;
            temp->next = NULL;
            delete temp;
        }
    }
    void pop_back()
{
    if (Head == NULL) 
    {
        return;
    }
    else if (Head == Tail) 
    {
        delete Head;
        Head = Tail = NULL;
    }
    else 
    {
        Node* temp = Tail;
        Node* prev = Head;
        while(prev->next!=Tail){
            prev = prev->next;
        }
        Tail = prev;
        Tail->next = Head;
        delete temp;
    }
}

    void print()
    {   
        if(Head==NULL) return;
        cout<<Head->value<<"->";
        Node *temp = Head->next;
        while (temp != Head)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout<<temp->value<<"->";
        cout << "NULL" << endl;
    }
};
int main()
{
    CircularList cll;
    cll.push_front(5);
    cll.push_front(6);
    cll.push_back(4);
    cll.pop_front();
    cll.pop_back();
    cll.print();
}