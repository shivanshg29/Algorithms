#include<iostream>
#include<vector>
using namespace std;
int n;
void subsetSum(vector<int>v,vector<int>subset,int target,int i){
    if(target==0){
        cout<<"[";
        for(int i=0;i<subset.size();i++){
            cout<<subset[i];
            cout<<",";
        }   
        cout<<"]";
        return;
    }
    if(i==n)
        return;
    subsetSum(v,subset,target,i+1);
    if(v[i]<=target){
        subset.push_back(v[i]);
        subsetSum(v,subset,target-v[i],i+1);
        subset.pop_back();
    }
}
int main(){
    vector<int>v={1,2,1};
    n=3;
    vector<int>subset;
    int target=3;
    subsetSum(v,subset,target,0);
}