class Solution {
public:
    
    // Check if we can ship within 'days' using capacity 'cap'
    bool check(vector<int>& weights, int days, int cap) {
        int countDays = 1;       // At least one day needed
        int currWeight = 0;
        
        for (int i = 0; i < weights.size(); i++) {
            currWeight += weights[i];
            
            if (currWeight > cap) {
                countDays++;             // Need one more day
                currWeight = weights[i];
            }
            
            if (countDays > days) 
                return false;
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int maxEle = INT_MIN;
        int sum = 0;
        
        // Find search space
        for (auto w : weights) {
            maxEle = max(maxEle, w);  // Minimum capacity
            sum += w;                 // Maximum capacity
        }
        
        int s = maxEle;
        int e = sum;
        int ans = 0;
        
        // Binary search on answer
        while (s <= e) {
            int mid = s + (e - s) / 2;
            
            if (check(weights, days, mid)) {
                ans = mid;
                e = mid - 1;   // Try smaller capacity
            } else {
                s = mid + 1;   // Increase capacity
            }
        }
        
        return ans;
    }
};
