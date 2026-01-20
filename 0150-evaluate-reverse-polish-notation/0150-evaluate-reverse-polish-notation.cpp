class Solution {
public:
    int performOperation(stack<int> &st, string str) {
        int operand1 = st.top();  // right operand
        st.pop();
        int operand2 = st.top();  // left operand
        st.pop();

        if (str == "*") return operand2 * operand1;
        if (str == "/") return operand2 / operand1;
        if (str == "+") return operand2 + operand1;
        if (str == "-") return operand2 - operand1;

        return 0; // safety
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int val = performOperation(st, str);
                st.push(val);
            } else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
