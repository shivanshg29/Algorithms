#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int maxSub(int*arr,int p,int q){
    if(p==q)
        return arr[p];
    int m=(p+q)/2;
    int maxL=maxSub(arr,p,m);
    int maxR=maxSub(arr,m+1,q);
    int sum=0,leftSub=INT_MIN,rightSub=INT_MIN;
    for(int i=m;i>=0;i--){
        sum+=arr[i];
        leftSub=max(leftSub,sum);
    }
    sum=0;
    for(int i=m+1;i<=q;i++){
        sum+=arr[i];
        rightSub=max(rightSub,sum);
    }
    int maxLR=leftSub+rightSub;
    return max(max(maxL,maxR),maxLR);
}
int main(){
    int arr[]={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSub(arr,0,8);
}