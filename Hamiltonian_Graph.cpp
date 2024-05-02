#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<bool>>&graph,vector<int>&path,int pos,int val){
    if(!graph[path[pos-1]][val]){
        return false;
    }
    for(int i=0;i<pos;i++){
        if(path[i]==val)
            return false;
    }
    return true;
}

bool is_ham(vector<vector<bool>>&graph,vector<int>&path,int pos){
    if(pos==graph.size())
        return true;
    for(int i=1;i<graph.size();i++){
        if(isSafe(graph,path,pos,i)){
            path[pos]=i;
            if(is_ham(graph,path,pos+1))
                return true;
            path[pos]=-1;
        }
    }
}

void ham_path(vector<vector<bool>>&graph){
    vector<int>path(graph.size(),-1);
    path[0]=0;
    if(is_ham(graph,path,1)){
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
    }
    else{
        cout<<"No Path exists";
    }
}
int main(){
    vector<vector<bool>> my_graph={
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    ham_path(my_graph);
}