class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size(); // total number of intervals
        sort(intervals.begin(), intervals.end()); // sort intervals by start time
        vector<vector<int>> ans;

        int start = intervals[0][0]; // initialize first interval
        int end = intervals[0][1];

        for(int i = 1; i < n; i++) {
            if(end >= intervals[i][0]) {
                start = min(start, intervals[i][0]); // merge overlapping intervals
                end = max(end, intervals[i][1]); 
            } else {
                ans.push_back({start, end}); // store non-overlapping interval
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, end}); // push the last interval
        return ans;
    }
};
