#include <iostream>
#include<limits.h>
using namespace std;
const int n=4;


void display(int m[][n+1]){
    for(int i=1;i<=n;i++){
        cout<<endl;
        for(int j=1;j<n;j++){
            cout<<m[i][j]<<" ";
        }
    }
}

void obst(int *p,int *q){
    int e[n+1][n+1],w[n+1][n+1],r[n+1][n+1];
    for(int i=1;i<=n+1;i++){
        e[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
    }
    for(int l=1;l<=n;l++){
        for(int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            e[i][j]=INT_MAX;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(int k=i;k<=j;k++){
                int t=e[i][k-1]+e[k+1][j]+w[i][j];
                if(t<e[i][j]){
                    e[i][j]=t;
                    r[i][j]=k;
                }
            }
        }
    }
    display(e);
    cout<<endl;
    cout<<"Cost is:"<<e[1][n-1]<<endl;
}
int main(){
    int p[]={0,1,2,4};
    int q[]={1,1,1,2};
    obst(p,q);
}