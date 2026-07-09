class Solution {
public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n1 = a.size();
        int n2 = b.size();
        
        // Always binary-search on the smaller array — keeps the search
        // range small: O(log(min(n1, n2))) instead of O(log(max(n1, n2))).
        if (n1 > n2) return kthElement(b, a, k);
        
        // cut1 (how many elements we take from `a`) must satisfy:
        //   - cut1 >= k - n2   -> b can supply at most n2 elements,
        //                         so a must cover whatever b can't.
        //   - cut1 >= 0        -> can't take negative elements.
        int start = max(k - n2, 0);
        
        // cut1 must also satisfy:
        //   - cut1 <= n1       -> can't take more than a has.
        //   - cut1 <= k        -> never need more than k elements total
        //                         from a single array.
        int end = min(k, n1);
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            int cut1 = mid;       // elements taken from a into the "left part"
            int cut2 = k - cut1;  // elements taken from b into the "left part"
                                   // (together always exactly k elements)
            
            // l1 = biggest element of `a` included on the left side.
            // If cut1 == 0, we've taken NOTHING from a, so there is no
            // "last left element" from a — treat it as -infinity so it
            // never wrongly wins a max() comparison later.
            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            
            // r1 = smallest element of `a` EXCLUDED (left on the right side).
            int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : b[cut2];
            
            // Valid partition check: the biggest thing on a's left side
            // must not exceed the smallest thing on b's right side, and
            // vice versa. (Checked "crossed" because within one array
            // it's already sorted — l1<=r1 is automatic.)
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);  // answer = max of everything on the left
            }
            else if (l1 > r2)
                end = mid - 1;   // took too many from a -> shrink cut1
            else
                start = mid + 1; // took too few from a -> grow cut1
        }
        return -1;
    }
};