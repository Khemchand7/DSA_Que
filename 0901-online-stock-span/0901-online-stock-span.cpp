class StockSpanner {
public:
    // Stores {price, index} in monotonic decreasing order of price
    stack<pair<int, int>> st;

    // Represents the current day's index
    int index;

    StockSpanner() {
        index = 0;
    }

    int next(int price) {

        // Remove all prices smaller than or equal to the current price
        // since they can never act as the previous greater price
        while (!st.empty() && st.top().first <= price)
            st.pop();

        int span = 0;

        // If no previous greater price exists,
        // the span includes all days so far
        if (st.empty()) {
            span = index + 1;
        }
        // Otherwise, span is the distance from the previous greater price
        else {
            span = index - st.top().second;
        }

        // Current price may become the previous greater price
        // for future incoming prices
        st.push({price, index});

        // Move to the next day
        index++;

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */