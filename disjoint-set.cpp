#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n = 5;

int *parent = new int[n];                   //initializing parent array
int *rank = new int[n];                     //initializing rank array

void initialize(){
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
}

//function to find the representative element

int find(int x){
    if(parent[x] != x){                      //applying path compression
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

//function for union of 2 elements

void unionOfEle(int a,int b){
    int x = find(a);
    int y = find(b);
    
    if(x == y){
        return;
    }
    
    if(rank[x] < rank[y]){
        parent[x] = y;
    }
    
    else if(rank[y] < rank[x]){
        parent[y] = x;
    }
    
    else{
        parent[y] = x;
        rank[x] = rank[x] + 1;
    }
}