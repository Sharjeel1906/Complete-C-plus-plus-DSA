#include <iostream>
using namespace std;

int partition(int arr[] ,int st,int end){
    int idx=st-1,pivot_val = arr[end];
    for(int i=st;i<end;i++){
        if(arr[i]<=pivot_val){
            idx++;
            swap(arr[i],arr[idx]);
        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}

void quicksort(int arr[] , int st ,int end){
    if(st<end){
        int pivot_ind = partition(arr,st,end);
        quicksort(arr,st,pivot_ind-1);
        quicksort(arr,pivot_ind+1,end);
    }
}

int main(){
    int size,val;
    cout<<"Entre the number of elements in the array"<<endl;
    cin>>size;
    int arr[size] = {};
    for(int i=0;i<size;i++){
        cout<<"Entre the value "<<i+1<<": ";
        cin>>val;
        arr[i] = val;
    }
    cout<<"Aray before quick sort: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    quicksort(arr,0,size-1);
    cout<<"Array After quick sort: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


}