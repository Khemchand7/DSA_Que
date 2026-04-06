class Solution {
  public:

    bool dfsHelper(int src, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &dfsTracker){

        visited[src] = 1;        // mark node as visited
        dfsTracker[src] = 1;     // mark node in current DFS recursion path
        
        for(auto nbr: adjList[src]){   // explore all neighbours
            
            if(!visited[nbr]){   // if neighbour not visited → DFS deeper
                
                if(dfsHelper(nbr, adjList, visited, dfsTracker))
                    return true;   // cycle detected in deeper recursion
            }
            
            else if(dfsTracker[nbr]){  // neighbour already in current DFS path → cycle
                return true;
            }
        }
        
        dfsTracker[src] = 0;   // remove node from recursion stack (backtracking)
        return false;          // no cycle found from this node
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adjList(V);   // adjacency list
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].push_back(v);   // directed edge u → v
        }
        
        vector<int> visited(V,0);      // track visited nodes
        vector<int> dfsTracker(V,0);   // track current DFS path
        
        for(int i = 0; i < V; i++){    // handle multiple components
            
            if(!visited[i]){
                if(dfsHelper(i, adjList, visited, dfsTracker))
                    return true;       // cycle exists
            }
        }
        
        return false;   // no cycle in graph
    }
};