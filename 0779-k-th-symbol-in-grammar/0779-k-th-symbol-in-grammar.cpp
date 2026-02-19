class Solution {
public:
    int kthGrammar(int n, int k) {

        // Base case: first position of grammar is always 0
        if (k == 1) return 0;

        // Find value of parent position in previous row
        // Parent index for 1-indexed k is floor(k/2)
        int val = kthGrammar(n - 1, (k+1) / 2);

        // If k is odd → LEFT child → same as parent //flipped because of 1 based indexing 
        // (positions 1,3,5,... are left children)
        if (k & 1) {
            return val;
        }
        else {
            // If k is even → RIGHT child → flipped value
            // (positions 2,4,6,... are right children)
            return 1 - val;
        }
    }
};
