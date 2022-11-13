class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int S , vector<bool> &visited , vector<bool> &order , vector<int> adj[]){
        visited[S] = true;
        order[S] = true;
        
        for(auto it : adj[S]){
            if(!visited[it]){
                if(dfs(it , visited , order , adj)){
                    return true;
                }
            }
            else if(order[it]){
                    return true;
             }
        }
        order[S] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<bool> order(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool f = dfs(i , visited , order , adj);
                
                if(f == true){
                    return true;
                }
            }
        }
        return false;
    }
};