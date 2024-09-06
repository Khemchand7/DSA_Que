class Solution {
public:
/*     // iterative solution
    int maxProfit(vector<int>& prices) {
        //================SOLUTION 1 ==============//
                int minPrice = INT_MAX;
                int maxProfit = INT_MIN;
                int index = -1;

                for(int i = 0;i<prices.size();i++){
                    if(prices[i] < minPrice){
                        minPrice = prices[i];
                    }
                    if((prices[i]-minPrice) > maxProfit){
                        maxProfit = prices[i]-minPrice;
                    }
                }
                if(maxProfit == INT_MIN) return 0;
                else return(maxProfit);
    } */

/*     //==========SOLUTION 2===========//
/*     Initialization: maxProfit is initialized to 0 because the minimum possible profit is zero (no transaction or a loss).
Conditional checks: The else-if statement ensures that we only calculate the profit when we encounter a price greater than the minimum price. This removes the redundant maxProfit == INT_MIN check and simplifies the code.
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // Track the minimum price encountered so far
        int maxProfit = 0;      // Track the maximum profit

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];  // Update the minimum price
            } else if(prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;  // Calculate and update max profit
            }
        }
        return maxProfit;
    } */

    //============SOLUTION 3 ==========// most optimized solution
     int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];  // Start with the first element
        int maxProfit = 0;         // Initial max profit is zero

        for(int i = 1; i < prices.size(); i++) {
            // Keep updating minPrice and maxProfit
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};