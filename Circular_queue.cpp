#include <iostream>
using namespace std;

void enqueue(int queue[], int* front, int* rear, int size, int data) {

    // 🔴 CHANGE 1: Circular Queue FULL condition
    if ((*front == 0 && *rear == size - 1) || (*front == *rear + 1)) {
        cout << "Queue Overflow" << endl;
        return;
    }

    // First insertion
    if (*front == -1) {
        *front = 0;
        *rear = 0;
    }
    // 🔴 CHANGE 2: Rear moves circularly
    else {
        *rear = (*rear + 1) % size;
    }

    queue[*rear] = data;
    cout << "Value " << data << " enqueued into Queue" << endl;
}

void dequeue(int queue[], int* front, int* rear, int size) {

    // Empty condition
    if (*front == -1) {
        cout << "Queue Underflow" << endl;
        return;
    }

    int x = queue[*front];

    // If only one element is present
    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    }
    // 🔴 CHANGE 3: Front moves circularly
    else {
        *front = (*front + 1) % size;
    }

    cout << "Value " << x << " dequeued from Queue" << endl;
}

bool isFull(int* front, int* rear, int size) {
    return ((*front == 0 && *rear == size - 1) || (*front == *rear + 1));
}

bool isEmpty(int* front) {
    return (*front == -1);
}

void peek(int queue[], int* front) {
    if (*front == -1) {
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "Peek is : " << queue[*front] << endl;
}

int main() {
    int front = -1, rear = -1, size = 0, input = 0;

    cout << "Which size of Queue do you want : " << endl;
    cin >> size;

    int queue[size] = {};

    // Enqueue elements
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i + 1 << ": " << endl;
        cin >> input;
        enqueue(queue, &front, &rear, size, input);
    }

    // Dequeue one element
    dequeue(queue, &front, &rear, size);

    cout << "Remaining elements of Queue are : " << endl;

    // Printing circular queue
    if (front != -1) {
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
    }

    cout << endl;
    cout << "IsFull : " << isFull(&front, &rear, size) << endl;
    cout << "IsEmpty : " << isEmpty(&front) << endl;
    peek(queue, &front);
}
