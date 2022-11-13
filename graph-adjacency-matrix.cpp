#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int matrix[20][20];

void addEdge(int u , int v , bool direction){
    //if direction = 0 => undirected graph
    //if direction = 1 => directed graph
    
    matrix[u][v] = 1;
    
    if(direction == 0){
        matrix[v][u] = 1;
    }
}

void print(int v){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int v;
    cout<<"Enter the number of Vertices"<<endl;
    cin>>v;
    
    for(int i=0;i<v;i++){
        int u,v;
        cin>>u>>v;
        
        addEdge(u , v , 0);
    }
    
    print(v);
    return 0;
}
