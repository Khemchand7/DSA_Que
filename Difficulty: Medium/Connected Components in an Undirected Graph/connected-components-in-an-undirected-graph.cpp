class Solution {
  public:
    void dfsHelper(int src, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &component){

    visited[src] = 1;              // mark current node as visited
    component.push_back(src);      // add node to current connected component

    for(auto nbr: adjList[src]){   // explore all neighbours of current node
        
        if(!visited[nbr]){         // visit neighbour only if not visited
            dfsHelper(nbr, adjList, visited, component);
        }
    }
}
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
         vector<vector<int>> adjList(V);   // adjacency list for graph (0..A-1)

    for(auto edge: edges){
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);     // undirected edge
        adjList[v].push_back(u);
    }

    vector<int> visited(V,0);        // track visited vertices
    vector<vector<int>> result;      // store all connected components

    for(int i = 0; i < V; i++){      // traverse all vertices
        
        if(!visited[i]){             // start DFS if vertex not visited
            vector<int> component;   // store nodes of current component
            
            dfsHelper(i, adjList, visited, component);  // find full component

            //sort(component.begin(), component.end());   // sort vertices inside component
            result.push_back(component);
        }
    }

    //sort(result.begin(), result.end());   // sort components by first element

    return result;
        
    }
};
