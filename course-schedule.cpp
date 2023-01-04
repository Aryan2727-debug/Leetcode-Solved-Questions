class Solution {
public:

    bool isCyclic(int S, vector<int> adj[], vector<int> &visited){

        if(visited[S] == 1){
            return true;
        }
        if(visited[S] == 0){
            visited[S] = 1;
            
            for(auto it : adj[S]){
                if(isCyclic(it, adj, visited)){
                    return true;
                }
            }
        }

        visited[S] = 2;
        return false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(numCourses, 0);

        for(int i=0;i<numCourses;i++){
            if(isCyclic(i, adj, visited)){
                return false;
            }
        }
        return true;
    }
};