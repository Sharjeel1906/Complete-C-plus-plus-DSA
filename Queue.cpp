#include <iostream>
using namespace std;

void enqueue(int queue[], int* front, int* rear, int size, int data) {
    if (*rear == size - 1) {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (*front == -1)
        *front = 0;

    queue[++(*rear)] = data;
    cout << "Value " << data << " enqueued into Queue" << endl;
}
void dequeue(int queue[], int* front) {
    if (*front == - 1) {
        cout << "Queue Underflow" << endl;
        return;
    }
    int x = queue[*front];
    *front = *front+1;

    cout << "Value " << x << " dequeued into Queue" << endl;
}
bool isfull(int* rear,int size){
    if(*rear==size-1){
        return true;
    }
    return false;
}
bool isEmpty(int* front){
    if(*front==-1){
        return true;
    }
    return false;
}
void peek(int queue[],int* front){
    if(*front==-1){
        cout<<"Queue is Empty"<<endl;
    }
    cout<<"Peek is : "<<queue[*front]<<endl;
}
int main() {
    int front = -1, rear = -1, size = 0, input = 0;

    cout << "Which size of Queue do you want : " << endl;
    cin >> size;

    int queue[size] = {};

    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": " << endl;
        cin >> input;
        enqueue(queue, &front, &rear, size, input);
    }
    dequeue(queue,&front);
    cout<<"Remaining elements of Queue are : "<<endl;
    for(int i=front;i<=rear;i++){
        cout<< queue[i]<<" ";
    }
    cout<<endl;
    cout<<"IsFull : "<<isfull(&rear,size)<<endl;
    cout<<"IsEmpty : "<<isEmpty(&front)<<endl;
    peek(queue,&front);
}
