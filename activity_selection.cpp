#include<iostream>
#include<algorithm>
using namespace std;
struct activity{
    int start,end;
};
static bool cmp(activity a,activity b){
    return a.end<b.end;
}
int activity_sel(activity arr[],int n){
    sort(arr,arr+n,cmp);
    int j=0,cnt=0;
    cout<<"("<<arr[0].start<<","<<arr[0].end<<"),";
    for(int i=1;i<n;i++){
        if(arr[j].end<=arr[i].start){
            cnt++;
            cout<<"("<<arr[i].start<<","<<arr[i].end<<"),";
            j=i;
        }
    }
    cout<<endl;
    return cnt+1;
}

int main(){
    activity arr[]={{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};
    cout<<activity_sel(arr,6);
}