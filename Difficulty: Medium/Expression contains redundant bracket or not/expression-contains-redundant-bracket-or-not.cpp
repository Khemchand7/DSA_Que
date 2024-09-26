//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
    stack<char> st;  // Stack to store characters of the expression

    // Iterate over the characters in the given string
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];  // Current character in the string
        
        // If the current character is an opening parenthesis '(' or an operator, push it to the stack
        //ignore alphabets
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else {
            // If the current character is a closing parenthesis ')'
            if (ch == ')') {
                int countOperator = 0;  // To count the number of operators between parentheses
                
                // Pop elements from the stack until the matching opening parenthesis '(' is found
                while (!st.empty() && st.top() != '(') {
                    char temp = st.top();  // Get the top element of the stack
                    
                    // If the top element is an operator, increase the count
                    if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
                        countOperator++;
                    }
                    
                    st.pop();  // Remove the top element from the stack
                }
                
                // If no operator was found between the parentheses, it indicates redundant parentheses
                if (countOperator == 0) {
                    return 1;  // Redundant parentheses found, return 1
                }
                
                st.pop();  // Pop the opening parenthesis '(' from the stack
            }
        }
    }

    return 0;  // No redundant parentheses found, return 0
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;
    }
}

// } Driver Code Ends