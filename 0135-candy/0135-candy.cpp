class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
    
    // Each child gets at least 1 candy initially
    vector<int> left(n,1), right(n,1);

    // Left → Right pass
    // Ensure: if current rating > left neighbor → give more candies
    for(int i = 1; i < n; i++){
        if( ratings[i] > ratings[i-1] ){
            left[i] = left[i-1] + 1; // build increasing sequence
        }
    }

    // Right → Left pass
    // Ensure: if current rating > right neighbor → give more candies
    for(int i = n-2; i >=0; i--){
        if(ratings[i] >  ratings[i+1] ){
            right[i] = right[i+1] + 1; // handle decreasing sequence
        }
    }
    
    int ans = 0;

    // Take max from both sides to satisfy both constraints
    for(int i = 0; i<n; i++ ){
        ans += max(left[i], right[i]);
    }

    return ans;
    }
};