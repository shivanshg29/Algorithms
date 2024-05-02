#include<iostream>
using namespace std;
const int n=4,maxW=5;

void display(int v[][maxW+1]){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=maxW;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Max Profit:"<<v[n][maxW];
}

void ele(int v[][maxW+1],int *w,int i,int j){
    if(i==0 || j==0){
        return;
    }
    if(v[i][j]!=v[i-1][j]){
        ele(v,w,i-1,j-w[i-1]);
        cout<<w[i-1]<<" ";
    }
    else{
        ele(v,w,i-1,j);
    }
}

void knapsack(int *w,int *b){
    int v[n+1][maxW+1];
    for(int i=0;i<=maxW;i++){
        v[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        v[i][0]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxW;j++){
            if(w[i-1]<=j){
                if(b[i-1]+v[i-1][j-w[i-1]]>v[i-1][j]){
                    v[i][j]=b[i-1]+v[i-1][j-w[i-1]];
                }
                else{
                    v[i][j]=v[i-1][j];
                }
            }
            else{
                v[i][j]=v[i-1][j];
            }
        }
    }
    display(v);
    cout<<endl;
    ele(v,w,n,maxW);
}

int main(){
    int w[]={2,3,4,5};
    int b[]={3,4,5,6};
    knapsack(w,b);
}