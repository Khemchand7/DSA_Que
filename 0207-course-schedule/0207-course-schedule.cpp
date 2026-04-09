class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(
            numCourses); // adjacency list: u -> list of courses depending on u
        vector<int> indegree(
            numCourses,
            0); // indegree[i] = number of prerequisites for course i

        queue<int> q; // queue for BFS (Kahn's Algorithm)

        int n = prerequisites.size();

        // build graph and compute indegree
        for (int i = 0; i < n; i++) {
            int u = prerequisites[i][0]; // prerequisite course
            int v = prerequisites[i][1]; // course dependent on u

            adjList[u].push_back(v); // directed edge u -> v
            indegree[v]++;           // v has one more prerequisite
        }

        // push all courses that have no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0; // number of courses that can be completed

        while (!q.empty()) {

            int frontNode = q.front();
            q.pop();

            count++; // course completed

            // reduce indegree of dependent courses
            for (auto nbr : adjList[frontNode]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0) // if all prerequisites satisfied
                    q.push(nbr);
            }
        }

        // if all courses processed → no cycle
        return (count == numCourses) ? 1 : 0;
    }
};