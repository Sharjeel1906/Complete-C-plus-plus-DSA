#include <iostream>
using namespace std;

void push(int stack[], int data, int* top, int size) { // LIFO
    if (*top == size - 1) {
        cout << "Stack Overflow" << endl;
    } else {
        *top = *top + 1;
        stack[*top] = data;
    }
}
void pop(int stack[],int* top){
    if(*top==-1){
        cout<<"Stack Underflow"<<endl;
    }else{
        int x = stack[*top];
        *top = *top -1;
        cout<<"Deleted element : "<<x<<endl;
    }
}
int peek(int stack[],int *top){
    if(*top==-1){
        return -1;
    }else{
        return stack[*top];
    }
}
bool isempty(int *top){
    if(*top==-1){
        return true;
    }else{
        return false;
    }
}
bool isfull(int *top,int size){
    if(*top==size-1){
        return true;
    }else{
        return false;
    }
}

int main() {
    int size = 0,input=0;
    cout << "Which size of stack do you want : " << endl;
    cin >> size;

    int stack[size] = {};
    int top = -1;
    
    for(int i=0;i<size;i++){
        cout<<"Entre the "<<i+1<< " elements of stack: "<<endl;
        cin>>input;
        push(stack,input , &top, size);
    }
    pop(stack,&top);
    cout<<"Its peek is : "<<peek(stack,&top)<<endl;
    cout<<"Is empty : "<<isempty(&top)<<endl;
    if(isempty(&top)){
        cout<<"Stack is Empty";
    }else{
        cout<<"Your stack is "<<endl;
        for (int i = 0; i <= top; i++) {
           cout << stack[i] << " ";
        }
    }
    
}
