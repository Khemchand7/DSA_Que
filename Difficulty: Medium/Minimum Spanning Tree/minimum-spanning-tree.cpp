class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {

        // adjacency list: node -> {neighbor, weight}
        vector<vector<pair<int,int>>> adjList(V);
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adjList[u].push_back({v,wt}); // add edge u -> v
            adjList[v].push_back({u,wt}); // because graph is undirected
        }
        
        vector<int> visited(V,0); // tracks nodes already included in MST
        
        // min heap storing {edge weight , node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        
        int cost = 0;
        
        pq.push({0,0}); // start Prim's algorithm from node 0
        
        while(!pq.empty()){
            
            auto [wt, node] = pq.top(); // get minimum weight edge
            pq.pop();
            
            if(visited[node]) continue; // skip if node already in MST
            
            cost += wt; // include this edge weight in MST
            visited[node] = 1; // mark node as part of MST
            
            // push all edges from this node to heap
            for(auto nbr: adjList[node]){
                int nextNode = nbr.first;
                int weight = nbr.second;
                
                if(!visited[nextNode]){
                    pq.push({weight, nextNode}); // candidate edge for MST
                }
            }
        }
        
        return cost; // total weight of Minimum Spanning Tree
    }
};