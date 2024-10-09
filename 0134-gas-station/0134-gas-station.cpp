class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit = 0;  // To track the total deficit of gas when we can't proceed from a certain station
        int balance = 0;  // To track the current gas balance at each station as we iterate
        int start = 0;    // To store the index of the potential starting station

        // Loop through each gas station
        for(int i = 0; i < gas.size(); i++){
            // Update the balance with the difference between the gas at current station and the cost to travel to the next station
            balance += gas[i] - cost[i];

            // If balance becomes negative, it means we can't proceed from the current starting station
            if(balance < 0){
                // Add the negative balance to deficit because we couldn't complete the journey starting from previous stations
                deficit += abs(balance);
                
                // Move the starting station to the next index since the current one isn't feasible
                start = i + 1;

                // Reset balance for the next segment of the journey
                balance = 0;
            }
        }

        // After the loop, if the total gas balance (balance) is greater than or equal to the deficit, we can complete the journey
        if(balance >= deficit){
            return start;  // The current start index is the valid starting station
        }
        else{
            return -1;  // If the balance isn't sufficient to cover the deficit, return -1 indicating no valid starting point
        }
    }
};
