class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;

        int index = -1;          // Stores index of the minimum element
        int minEle = INT_MAX;    // Stores the minimum element found so far

        while(start <= end){
            int mid = start + (end - start)/2;

            // If left half is sorted, its first element is the minimum of this half
            if(arr[start] <= arr[mid]){
                if(arr[start] < minEle){
                    index = start;
                    minEle = arr[start];   // Update minimum element
                }
                start = mid + 1;           // Search in the right half
            }
            else{
                // Minimum lies in the left unsorted half (mid can be the answer)
                if(arr[mid] < minEle){
                    index = mid;
                    minEle = arr[mid];     // Update minimum element
                }
                end = mid - 1;             // Continue searching on the left
            }
        }

        return index;   // Index of minimum element = number of rotations
    }
};