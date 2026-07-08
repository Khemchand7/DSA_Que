class Solution {
public:
    int numberOfBouquet(vector<int>& bloomDay, int totalBouquets, int flowersPerBouquet, int currentDay, int size){
        int bouquetCount = 0;
        int consecutiveFlowers = 0;

        for(int i = 0; i < size; i++){
            if(bloomDay[i] <= currentDay){
                consecutiveFlowers++;

                // Form a bouquet whenever k adjacent flowers are available
                if(consecutiveFlowers == flowersPerBouquet){
                    bouquetCount++;
                    consecutiveFlowers = 0;
                }
            }
            else{
                // Reset count if an unbloomed flower breaks the sequence
                consecutiveFlowers = 0;
            }
        }
        return bouquetCount;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // edge case : If the total flowers available are fewer than that, the task is impossible.
        if(n < 1LL * m * k) return -1;

        // Search space: minimum bloom day to maximum bloom day
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        int answer = -1;

        while(start <= end){
            // Check if it's possible to make bouquets on the current day
            int mid = start + (end - start) / 2;

            int bouquetsFormed = numberOfBouquet(bloomDay, m, k, mid, n);

            if(bouquetsFormed >= m){
                // Current day works, try to find an earlier valid day
                answer = mid;
                end = mid - 1;
            }
            else{
                // Not enough bouquets, need to wait for more flowers to bloom
                start = mid + 1;
            }
        }

        return answer;
    }
};