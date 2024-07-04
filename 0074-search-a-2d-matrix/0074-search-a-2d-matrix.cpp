class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int n=row*col;//total no. of blocks if 2 rows 2 col then 4
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            int rowIndex = mid / col;
            int colIndex = mid % col;
            int currNumber=matrix[rowIndex][colIndex];
            if(currNumber==target){
                return true;
            }
            else if(currNumber>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
      return false;  
    }
};