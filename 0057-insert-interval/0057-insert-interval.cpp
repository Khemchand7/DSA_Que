class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;

        // Add all intervals before newInterval (no overlap)
        // do not overlap when start of newInterval > end of current interval
        while (i < n && newInterval[0] > intervals[i][1]) { 
            vector<int> temp;
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i][1]);
            ans.push_back(temp);
            i++;
        }

        // Merge overlapping intervals with newInterval
        //overlap when end of newINterval >= start of current Interval
        while (i < n && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // Add the merged interval
        ans.push_back({newInterval[0], newInterval[1]});

        // Add remaining intervals after newInterval
        while (i < n) {
            ans.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }

        return ans;
    }
};
