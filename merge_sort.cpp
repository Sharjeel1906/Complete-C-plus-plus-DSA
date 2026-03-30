#include <iostream>
#include<vector>
using namespace std;

void merge(int arr[],int mid,int st, int end){
    vector<int> temp;
    int i = st , j = mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(int idx = 0;idx<temp.size();idx++){
        arr[idx+st] = temp[idx];
    }
}

void merge_sort(int arr[] , int st ,int end){
    if(st<end){
        int mid = (st+end)/2;
        merge_sort(arr,st,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,mid,st,end);
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
    cout<<"Aray before Merge sort: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    merge_sort(arr,0,size-1);
    cout<<"Array After Merge sort: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


}