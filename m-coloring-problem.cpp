class Solution{
public:

    bool isSafe(int node, int color[], bool graph[101][101], int n, int col){
        
        //col = color which we are trying to use currently
        //color = array which stores the colors
        
        for(int k=0;k<n;k++){
            //checking if adjacent node has the same color or not
            if(k != node && graph[k][node] == 1 && color[k] == col){
                return false;
            }
        }
        return true;
    }
    
    bool solve(int node, int color[], int m, int n, bool graph[101][101]){
        //base case
        if(node == n){
            return true;
        }
        
        //checking for every color from 1 to m
        for(int i=1;i<=m;i++){
            if(isSafe(node, color, graph, n, i)){
                color[node] = i;
                //recursive call
                if(solve(node+1, color, m, n, graph)){
                    return true;
                }
                //backtracking
                color[node] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        
        if(solve(0, color, m, n, graph)){
            return true;
        }
        
        return false;
    }
};