class Solution {
  public:
  
    // Returns:
    // 1 -> mid^n == m
    // 0 -> mid^n < m
    // 2 -> mid^n > m
    int check(int mid, int n, int m){
        long long ans = 1;

        for(int i = 1; i <= n; i++){
            ans *= mid;

            // Stop early if value exceeds m.
            if(ans > m)
                return 2;
        }

        if(ans == m) return 1;
        return 0;
    }

    int nthRoot(int n, int m) {

        // Edge case: nth root of 0 is always 0.
        if(m == 0)
            return 0;

        int start = 1;
        int end = m;

        while(start <= end){
            int mid = start + (end - start) / 2;

            int result = check(mid, n, m);

            if(result == 1)
                return mid;
            else if(result == 0)
                start = mid + 1;
            else
                end = mid - 1;
        }

        return -1;
    }
};