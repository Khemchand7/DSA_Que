class Solution {
public:
    long long calculateTime(vector<int>& piles, int givenTime, int n){
        long long  timeReq = 0;

        for(int i = 0; i < n; i++){
            // Hours required for current pile at the given eating speed
            // need to use double as both piles[i] and given time is integer and integer division will give
            // floor value first then no meaning of using ceil value
            timeReq += ceil((double)piles[i] / givenTime);
        }
        return timeReq;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        // Minimum possible speed is 1 and maximum is the largest pile
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        int k = -1;

        while(start <= end){
            // Find the middle eating speed
            int mid = start + (end - start) / 2;

            // Calculate total hours needed at current speed
            long long timeReq = calculateTime(piles, mid, n);

            if(timeReq <= h){
                // Current speed works, try to find a smaller valid speed
                k = mid;
                end = mid - 1;
            }
            else{
                // Speed is too slow, increase the eating speed
                start = mid + 1;
            }
        }

        return k;
    }
};