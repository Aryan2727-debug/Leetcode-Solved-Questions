class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //declaring a min-heap(priority queue)
        priority_queue < pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        
        //declaring the distance array
        vector<int> dist(V);
        
        //marking all elements of array as infinite
        for(int i=0;i<V;i++){
            dist[i] = 1e9;
        }
        
        //distance from source to source is always 0
        dist[S] = 0;
        pq.push({0,S});
        
        //iterating in the priority queue
        while(!pq.empty()){
            int dis = pq.top().first;     //picking up the distance of node
            int node = pq.top().second;    //picking up the node itself
            pq.pop();
            
            for(auto it : adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode] , adjNode});
                }
            }
        }
        return dist;
    }
};
