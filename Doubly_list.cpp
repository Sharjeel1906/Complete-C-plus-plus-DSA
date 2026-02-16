#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int val)
    {
        value = val;
        next = prev = NULL;
    }
};
class DoublyList
{
    Node *Head;
    Node *Tail;
public:
    DoublyList()
    {
        Head = Tail = NULL;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (Head == NULL)
        {
            Head = Tail = newNode;
        }
        else
        {
            newNode->next = Head;
            Head->prev = newNode;
            Head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (Head == NULL)
        {
            Head = Tail = newNode;
        }
        else
        {
            newNode->prev = Tail;
            Tail->next = newNode;
            Tail = newNode;
        }
    }
    
    void pop_front(){
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
        Node* temp = Head;
        Head = Head->next;
        Head->prev = NULL;
        delete temp;
    }
}

    void pop_back(){
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
        Tail = Tail->prev;
        Tail->next = NULL;
        delete temp;
    }
}
    
    void search(int val){
        bool found = false;   // FIXED
        int idx = 0;
        Node *temp = Head;

        while (temp != NULL)
        {
            if (temp->value == val)
            {
                cout << val << " Found at index : " << idx << endl;
                found = true;
                break;
            }
            temp = temp->next;
            idx++;
        }

        if (!found)
            cout << "Invalid key Not available in list" << endl;
    }

    void no_of_nodes()
    {
        int num = 0;
        Node *temp = Head;

        while (temp != NULL)
        {
            num++;
            temp = temp->next;
        }
        cout << "No of nodes in linkedlist : " << num << endl;
    }
     
   void insert(int val, int pos)
{
    if (pos < 0)
        return;

    if (pos == 0)
    {
        push_front(val);
        return;
    }

    Node *temp = Head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (temp == Tail)
    {
        push_back(val);
        return;
    }

    Node *newNode = new Node(val);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}
   
    void delete_at_point(int pos)
    {
        if (pos < 0)
            return;

        if (pos == 0)
        {
            pop_front();
            return;
        }

        Node *temp = Head;
        for (int i = 0; i < pos && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        if (temp == Tail)
        {
            pop_back();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    Node *merge_sorted_list(Node *head1, Node *head2)
    {
        if (head1 == NULL || head2 == NULL)
        {
            return head1 == NULL ? head2 : head1;
        }
        if (head1->value <= head2->value)
        {
            head1->next = merge_sorted_list(head1->next, head2);
            if (head1->next != NULL)
                head1->next->prev = head1;

            head1->prev = NULL;
            return head1;
        }
        else
        {
            head2->next = merge_sorted_list(head1, head2->next);
            if (head2->next != NULL)
                head2->next->prev = head2;

            head2->prev = NULL;
            return head2;
        }
    }
    
    void reverse()
{
    Node* curr = Head;
    Node* temp = NULL;

    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    temp = Head;
    Head = Tail;
    Tail = temp;
}

    void print()
    {
        Node *temp = Head;
        while (temp != NULL)
        {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    DoublyList dll;
    dll.push_front(5);
    dll.push_front(6);
    dll.push_back(4);
    dll.search(4);
    dll.no_of_nodes();
    dll.insert(7,2);
    dll.print();
}