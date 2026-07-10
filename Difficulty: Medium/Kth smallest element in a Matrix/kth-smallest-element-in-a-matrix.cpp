class Solution {
  public:
    // same helper as before: count elements <= x in a single sorted row
    int upperBound(vector<int>& arr, int x, int m){
        int ans = m;
        int start = 0;
        int end = m - 1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] > x){
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
    
    // same helper as before: count elements <= x across the whole matrix
    int countSmallerElem(vector<vector<int>> &mat, int x, int n, int m){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += upperBound(mat[i], x, m);
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        int start = INT_MAX;
        int end = INT_MIN;
        for(int i = 0; i < n; i++){
            start = min(start, mat[i][0]);
            end = max(end, mat[i][m-1]);
        }
        
        // 0-indexed position we want: kth smallest sits at index k-1
        int req = k - 1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            int cntSmaller = countSmallerElem(mat, mid, n, m);
            
            if(cntSmaller <= req)
                start = mid + 1;
            else
                end = mid - 1;
        }
        
        return start;
    }
};