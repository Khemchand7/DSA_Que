class Solution {
  public:
    // Given a sorted row 'arr' of length m, find how many elements are <= x.
    // This works by finding the index of the first element strictly greater
    // than x — everything before that index is <= x, so the index itself
    // equals the count of elements <= x.
    int upperBound(vector<int>& arr, int x, int m){
        int ans = m;   // default: if no element is > x, ALL m elements are <= x
        int start = 0;
        int end = m - 1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            
            if(arr[mid] > x){
                // mid could be our answer — record it, then keep looking
                // further left for an even earlier "first greater" index
                ans = mid;
                end = mid - 1;
            }
            else
                // arr[mid] <= x, so the first element > x must be further right
                start = mid + 1;
        }
        return ans;
    }
    
    // Counts how many elements in the ENTIRE matrix are <= x,
    // by summing the per-row counts from upperBound.
    int countSmallerElem(vector<vector<int>> &mat, int x, int n, int m){
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            cnt += upperBound(mat[i], x, m);
        }
        return cnt;
    }
    
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Binary search happens over VALUES, not indices.
        // So start/end must cover the full range of values in the matrix.
        int start = INT_MAX;
        int end = INT_MIN;
        
        for(int i = 0; i < n; i++){
            // smallest possible value = smallest first-element across rows
            start = min(start, mat[i][0]);
            // largest possible value = largest last-element across rows
            end = max(end, mat[i][m-1]);
        }
        
        // 0-indexed position of the median in the fully sorted (virtual) array
        int req = (n * m)/2;
        
        // We're looking for the smallest value 'mid' such that the count of
        // elements <= mid is MORE than req — that value is the median.
        while(start <= end){
            int mid = start + (end - start)/2;
            
            // how many elements in the matrix are <= mid?
            int cntSmaller = countSmallerElem(mat, mid, n, m);
            
            if(cntSmaller <= req)
                // not enough elements <= mid yet, so mid is too small —
                // the median must be strictly greater, search right half
                start = mid + 1;
            else
                // mid already covers enough elements (maybe more than needed) —
                // it's a valid candidate, but try to find a smaller one, search left half
                end = mid - 1;
        }
        
        // loop exits when start > end; start has converged on the smallest
        // value where cntSmaller > req, which is exactly the median
        return start;
    }
};