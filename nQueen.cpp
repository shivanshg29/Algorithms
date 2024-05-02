#include<iostream>
#include<cmath>
using namespace std;
int n;
void print(int *x){
	for(int i=1;i<=n;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
bool place(int *x,int k,int i){
	for(int j=1;j<k;j++){
		if(x[j]==i || (abs(x[j]-i)==abs(j-k))){
			return false;
		}
	}
	return true;
}
void nQueen(int *x,int k){
	for(int i=1;i<=n;i++){
		if(place(x,k,i)){
			x[k]=i;
			if(k==n){
				print(x);
				return;
			}
			else{
				nQueen(x,k+1);
			}
		}
	}
}
int main(){
	cout<<"Enter no of queens:";cin>>n;
	int x[n+1];
	nQueen(x,1);	
}