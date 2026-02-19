class Solution {
public:
    int kthGrammar(int n, int k) {

        // Base case: 1st row contains only one symbol → 0
        if(n == 1) return 0;

        // Mid = size of first half of row n
        // Total length = 2^(n-1)
        // Half length  = 2^(n-2)
        int mid = 1 << (n - 2);

        // If k lies in first half
        // → value is same as previous row at position k
        if(k <= mid){
            return kthGrammar(n - 1, k);
        }

        // If k lies in second half
        // → value is inverse of corresponding position in first half
        // → mapped to (k - mid) in previous row
        return 1 - kthGrammar(n - 1, k - mid);
    }
};
