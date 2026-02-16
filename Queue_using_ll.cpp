#include <iostream>
using namespace std;

#include "linked_list.cpp"

class Queue
{
private:
    LinkedList ll;
public:
    void enqueue(int val){
        ll.Pushback(val);
        cout << val << " enqueued" << endl;
    }
    void dequeue(){
        if (ll.Head == NULL){
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << ll.Head->value << " dequeued" << endl;
        ll.Popfront();
    }
    int peek(){
        if (ll.Head == NULL)
            return -1;
        return ll.Head->value;
    }
    bool isEmpty(){
        return ll.Head == NULL;
    }
    void printQueue() {
    if (ll.Head == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: ";
    ll.print();
}
};

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();
    cout << "Front element: " << q.peek() << endl;
    
    q.printQueue();
    return 0;
}
