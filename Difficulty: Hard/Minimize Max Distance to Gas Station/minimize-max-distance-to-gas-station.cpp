class Solution {
public:
    double minMaxDist(vector<int> &stations, int K) {
        int n = stations.size();
        
        // No section exists if there is only one gas station.
        if(n <= 1)
            return 0.0;

        // Stores how many new gas stations are added in each section.
        vector<int> howMany(n - 1, 0);

        // Max heap -> {current maximum distance in a section, section index}
        priority_queue<pair<long double, int>> pq;

        // Initially, each section has its original distance.
        for(int i = 0; i < n - 1; i++){
            pq.push({stations[i + 1] - stations[i], i});
        }

        // Greedily place each new gas station in the section
        // having the largest current distance.
        for(int gasStation = 1; gasStation <= K; gasStation++){

            auto tp = pq.top();
            pq.pop();

            int sectionIndex = tp.second;
            howMany[sectionIndex]++;// added one gas station

            // Recalculate the maximum distance for this section
            // after adding one more gas station.
            long double iniDiff = stations[sectionIndex + 1] - stations[sectionIndex];
            long double newDiff = iniDiff / (long double)(howMany[sectionIndex] + 1);

            // Push the updated section back into the heap.
            pq.push({newDiff, sectionIndex});
        }

        // The largest remaining section length is the answer.
        return pq.top().first;
    }
};

// Complexity
// Time: O((N+K)logN)
// Space: O(N)