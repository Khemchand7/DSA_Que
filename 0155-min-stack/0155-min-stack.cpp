class MinStack {
public:
    stack<int> st;
    stack<int> minStack;

    MinStack() {
        // Both stacks start empty, so no initialization is required
    }

    void push(int value) {

        // Store the minimum value at the current stack level
        if (st.empty()) {
            minStack.push(value);
        }
        else {
            minStack.push(min(value, minStack.top()));
        }

        // Store the actual value in the normal stack
        st.push(value);
    }

    void pop() {

        // Both stacks represent the same stack levels,
        // so remove the top from both
        st.pop();
        minStack.pop();
    }

    int top() {
        return st.top();   // Return the actual top value
    }

    int getMin() {
        return minStack.top();   // Minimum is always at the top of minStack
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */