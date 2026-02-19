class Solution {
public:
// Phone keypad mapping for digits 0–9
const vector<string> mapping = {
    "0","1","abc","def","ghi",
    "jkl","mno","pqrs","tuv","wxyz"
};

void helper(string A, int idx, string &temp, vector<string>& ans){
    
    // Base case: all digits processed → one combination formed
    if(idx >= A.length()){
        ans.push_back(temp);
        return;
    }

    // Convert current digit character to integer
    int digit = A[idx] - '0';

    // Get corresponding letters for this digit
    string letters = mapping[digit];

    // Try each possible letter (backtracking)
    for(int i = 0; i < letters.length(); i++){
        
        temp.push_back(letters[i]);      // Choose
        
        helper(A, idx + 1, temp, ans);   // Explore next digit
        
        temp.pop_back();                 // Backtrack
    }
}


vector<string> letterCombinations(string digits) {
    
    string temp = "";        // Current combination being built
    vector<string> ans;      // Stores all valid combinations
    int idx = 0;             // Start from first digit

    // Edge case: empty input → no combinations
    if(digits.length() == 0) return ans;

    // Call your helper with digits instead of A
    helper(digits, idx, temp, ans);

    return ans;              // Final result
}

};