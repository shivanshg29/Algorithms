#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Job{
    char id;
    int deadline;
    int profit;
};
static bool cmp(Job a,Job b){
    return a.profit>b.profit;
}
void job_sequencing(Job arr[],int n){
    sort(arr,arr+n,cmp);
    int maxi=-1;
    for(int i=0;i<n;i++){
        if(maxi<arr[i].deadline){
            maxi=arr[i].deadline;
        }
    }
    vector<char>dur(maxi,'x');
    for(int i=0;i<n;i++){
        int j=arr[i].deadline-1;
        while(j>=0 && dur[j]!='x'){
            j--;
        }
        if(dur[j]=='x')
            dur[j]=arr[i].id;
    }
    for(int i=0;i<maxi;i++){
        cout<<dur[i]<<" ";
    }
}
int main(){
    Job arr[]={{ 'a', 2, 100 },{ 'b', 1, 19 },{ 'c', 2, 27 },{ 'd', 1, 25 },{ 'e', 3, 15 } };
    job_sequencing(arr,5);
}