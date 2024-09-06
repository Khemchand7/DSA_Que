class Solution {
public:
//iterative solution
    int maxProfit(vector<int>& prices) {
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
    }
};