class Solution {
public:
    bool isValid(string s) {
        
        // Stack to keep track of opening brackets
        stack<char> st;
        
        // Traverse through each character of the input string
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            // If the character is an opening bracket, push it onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch); // open brackett
            } else {
                // Closed bracket encountered, now we need to check if it matches the top of the stack
                
                // If stack is empty, there's no matching opening bracket for this closing one
                if (st.empty()) {
                    // stack empty hai aur usme close brackett ko check karna hai
                    return false;
                } else {
                    // Stack is not empty, so we check if the top matches the current closing bracket
                    
                    // For closing parenthesis ')', top of the stack should be '('
                    if (ch == ')' && st.top() == '(') { 
                        // top ko access kar rhe hai so make sure empty na ho stack
                        st.pop(); // valid match, so pop the top
                    } 
                    // For closing curly brace '}', top of the stack should be '{'
                    else if (ch == '}' && st.top() == '{') {
                        st.pop(); // valid match, so pop the top
                    } 
                    // For closing square bracket ']', top of the stack should be '['
                    else if (ch == ']' && st.top() == '[') {
                        st.pop(); // valid match, so pop the top
                    } 
                    else {
                        // If none of the above conditions are met, the brackets are not balanced
                        // st.top() ka element char se match nhi hua
                        return false;
                    }
                }
            }
        }
        
        // After traversing all characters, if the stack is empty, all opening brackets have valid matches
        if(st.empty()) {
            return true;
        } else {
            // If stack is not empty, it means there are unmatched opening brackets
            return false;
        }
    };
};
