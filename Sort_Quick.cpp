#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int *a,int low,int high){
    int piv=a[high],i=low-1,j;
    for(j=low;j<high;j++){
        if(a[j]<=piv){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}
void quicksort(int *a,int low,int high){
    int p;
    if(low<high){
    p=partition(a,low,high);
    quicksort(a,low,p-1);
    quicksort(a,p+1,high);
    }
}
int main(){
    int a[]={9,8,7,6,5,4,3,2,1};
    quicksort(a,0,8);
    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }
}