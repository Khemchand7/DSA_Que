
void longestPalindromeOdd(string A, int &maxLen, int &start, int size) {
    for (int c = 0; c < size; c++) {
        int len = 1; // Initialize length of palindrome centered at 'c'
        int i = c - 1;
        int j = c + 1;
        
        // Expand around center for odd-length palindromes
        while (i >= 0 && j < size && A[i] == A[j]) {
            len += 2; // Increase palindrome length by 2
            i--;
            j++;
        }
        
        // Update max palindrome length and start index
        if (len > maxLen) {
            maxLen = len;
            start = i + 1; // Adjust to correct start index
        }
    }
}

void longestPalindromeEven(string A, int &maxLen, int &start, int size) {
    int C1 = 0;
    int C2 = 1;
    
    // Iterate through potential even-length palindrome centers
    while (C2 < size) {
        int len = 0;
        int i = C1;
        int j = C2;
        
        // Expand around center for even-length palindromes
        while (i >= 0 && j < size && A[i] == A[j]) {
            len += 2; // Increase palindrome length by 2
            i--;
            j++;
        }
        
        // Update max palindrome length and start index
        if (len > maxLen) {
            maxLen = len;
            start = i + 1; // Adjust to correct start index
        }
        
        C1++;
        C2++;
    }
}
class Solution {
public:
    string longestPalindrome(string s) {
         int n = s.length();
    int maxLen = 0;
    int start = 0;

    // Find longest odd-length palindrome
    longestPalindromeOdd(s, maxLen, start, n);
    
    // Find longest even-length palindrome
    longestPalindromeEven(s, maxLen, start, n);

    return s.substr(start, maxLen); // Extract and return the longest palindrome
    }
};