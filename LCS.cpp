#include<iostream>
#include<vector>
using namespace std;
int sx,sy;
void display(vector<vector<int>>arr){
    for(int i=0;i<=sx;i++){
        for(int j=0;j<=sy;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void LCSseq(vector<vector<char>>arr,vector<char>x,int i,int j){
    if(i==0 || j==0)
        return;
    if(arr[i][j]=='D'){
        LCSseq(arr,x,i-1,j-1);
        cout<<x[i-1];
    }
    else if(arr[i][j]=='U'){
        LCSseq(arr,x,i-1,j);
    }
    else{
        LCSseq(arr,x,i,j-1);
    }
}

void LCS(vector<char>x,vector<char>y){
    sx=x.size(),sy=y.size();
    vector<vector<int>>tab(sx+1,vector<int>(sy+1));
    vector<vector<char>>arr(sx+1,vector<char>(sy+1));
    for(int i=0;i<=sx;i++){
        for(int j=0;j<=sy;j++){
            if(i==0||j==0){
                tab[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                tab[i][j]=tab[i-1][j-1]+1;
                arr[i][j]='D';
            }
            else{
                tab[i][j]=max(tab[i-1][j],tab[i][j-1]);
                if(tab[i][j]==tab[i-1][j])
                    arr[i][j]='U';
                else
                    arr[i][j]='L';
            }
        }
    }
    display(tab);
    LCSseq(arr,x,sx,sy);
}

int main(){
    vector<char>x={'A','B','C','B','D','A','B'};
    vector<char>y={'B','D','C','A','B','A'};
    LCS(x,y);
}