class Solution {
public:
    double check(vector<int>& dist, int minSpeed, int n){
        double time = 0;

        // All trains except the last must depart at an integer hour,
        // so use ceiling division for their travel time.
        for(int i = 0; i < n - 1; i++){
            //time += ceil((double)dist[i] / minSpeed);
            time += (dist[i] + minSpeed - 1) / minSpeed;
        }

        // Last train can take fractional time.
        time += (double)dist[n - 1] / minSpeed;

        return time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();

        int start = 1;
        int end = 1e7;   // Maximum possible speed as per constraints.

        int ans = -1;

        // Binary Search on answer (minimum valid speed).
        while(start <= end){
            int mid = start + (end - start) / 2;

            double time = check(dist, mid, n);

            if(time <= hour){
                ans = mid;          // Valid speed, try to minimize it.
                end = mid - 1;
            }
            else{
                start = mid + 1;    // Need a higher speed.
            }
        }

        return ans;
    }
};