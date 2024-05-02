#include<iostream>
using namespace std;

void merge(int *arr,int l,int mid,int r){
    int left[mid-l+1],right[r-mid];
    for(int i=0;i<(mid-l+1);i++){
        left[i]=arr[l+i];
    }
    for(int i=0;i<(r-mid);i++){
        right[i]=arr[mid+1+i];
    }

    int i=0,j=0,k=l;
    while(i<mid-l+1 && j<r-mid){
        if(left[i]>=right[j]){
            arr[k++]=right[j++];
        }
        else{
            arr[k++]=left[i++];
        }
    }

    while(i<mid-l+1){
        arr[k++]=left[i++];
    }

    while(j<r-mid){
        arr[k++]=right[j++];    
    }
}

void mergeSort(int *arr,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    mergeSort(arr,0,8);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
}