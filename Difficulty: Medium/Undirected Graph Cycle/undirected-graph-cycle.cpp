class Solution {
  public:
    int bfsCycleHelper(int src, vector<vector<int>> &adjList, vector<int> &visited){
        queue<pair<int,int>> q; 
        
        visited[src] = 1;                 // mark source as visited
        q.push({src,-1});                 // push node with parent = -1
        
        while(!q.empty()){
            auto frontNode = q.front();   // get front element
            q.pop();                      // remove processed node
            
            int node = frontNode.first;  // current node
            int parent = frontNode.second; // parent of current node
            
            for(auto nbr: adjList[node]){ // traverse all neighbours
                
                if(!visited[nbr]){        // if neighbour not visited
                    visited[nbr] = 1;
                    q.push({nbr,node}); // push neighbour into queue
                }
                else if(nbr != parent)    // visited neighbour but not parent → cycle
                    return 1;
            }
            
        }
        
        return 0;                         // no cycle found
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);   // adjacency list
        
        // build graph
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);      // undirected graph
        }
        
        vector<int> visited(V,0);
        
        // handle disconnected components
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(bfsCycleHelper(i, adjList, visited))
                    return true;
            }
        }
        
        return false;                     // no cycle in graph
    }
};