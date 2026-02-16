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

    void PushFront(int val)
    {
        Node *newNode = new Node(val);
        if (Head == NULL)
        {
            Head = Tail = newNode;
            return;
        }
        newNode->next = Head;
        Head = newNode;
    }

    void Pushback(int val)
    {
        Node *newNode = new Node(val);
        if (Head == NULL)
        {
            Head = Tail = newNode;
            return;
        }
        Tail->next = newNode;
        Tail = newNode;
    }

    void Popfront()
    {
        if (Head == NULL)
            return;

        Node *temp = Head;
        Head = Head->next;
        delete temp;
    }

    void Popback()
    {
        if (Head == NULL)
            return;

        if (Head == Tail)
        {
            delete Head;
            Head = Tail = NULL;
            return;
        }

        Node *temp = Head;
        while (temp->next != Tail)
        {
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;
        Tail->next = NULL;
    }

    void insert(int val, int pos)
    {
        if (pos < 0)
            return;

        if (pos == 0)
        {
            PushFront(val);
            return;
        }

        Node *temp = Head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void search(int val)
    {
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

    void reverse()
    {
        Node *curr = Head;
        Node *prev = NULL;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        Head = prev;
    }

    void findmid()
    {
        Node *slow = Head;
        Node *fast = Head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle value is " << slow->value << endl;
    }

    bool detect_cycle()
    {
        Node *slow = Head;
        Node *fast = Head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }

    Node *get_cycle_node()
    {
        Node *slow = Head;
        Node *fast = Head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                slow = Head; 

                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;   // cycle start
            }
        }
        return NULL;
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

    Node* merge_sorted_list(Node* head1,Node* head2){
        if(head1==NULL || head2==NULL){
            return head1==NULL ?head2:head1;
        }
        if(head1->value<=head2->value){
            head1->next = merge_sorted_list(head1->next,head2);
            return head1;
        }else{
            head2->next = merge_sorted_list(head1,head2->next);
            return head2;
        }
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

// int main()
// {
//     LinkedList ll1,ll2; 
    
//     ll1.Pushback(1);
//     ll1.Pushback(2);
//     ll1.Pushback(3);
//     ll1.Pushback(5);

//     ll2.Pushback(6);
//     ll2.Pushback(7);
//     ll2.Pushback(8);
//     ll2.Pushback(9);
//     ll2.Pushback(10);
//     Node* head = ll1.merge_sorted_list(ll1.Head, ll2.Head);
//     Node *temp = head;
//         while (temp != NULL)
//         {
//             cout << temp->value << " -> ";
//             temp = temp->next;
//         }
//         cout << "NULL" << endl;
//     // cout << ll.detect_cycle() << endl;

//     // Node *cycleNode = ll.get_cycle_node();
//     // if (cycleNode == NULL)
//     // {
//     //     cout << "No cycle exist" << endl;
//     // }
//     // else
//     // {
//     //     cout << cycleNode->value << endl;
//     // }

//     return 0;
// }
