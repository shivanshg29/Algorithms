#include<iostream>
#include <algorithm>
using namespace std;
struct knapsack{
    int id;
    int profit;
    int weight;
};
static bool cmp(knapsack a,knapsack b){
    double c1=(double)a.profit/(double)a.weight;
    double c2=(double)b.profit/(double)b.weight;
    return c1>c2;
}
int frac_knapsack(knapsack arr[],int n,int wt){
    sort(arr,arr+n,cmp);
    int i=0;
    double profit=0.0;
    for(int i=0;i<n;i++){
        if(wt>=arr[i].weight){
            wt-=arr[i].weight;
            profit+=arr[i].profit;
        }
        else{
            profit+=arr[i].profit*((double)wt/(double)arr[i].weight);
            break;
        }
    }
    return profit;
}
int main(){
    knapsack arr[]={{1,60,10},{2,100,20}, {3,120,30}};
    int wt=50;
    cout<<frac_knapsack(arr,3,wt);
}