class Solution {
  public:
    bool check(vector<int> &stalls, int totalCows, int n, int d){
        int cowPlaced = 1;                 // first cow placed at 0th stall
        int lastPlaceCowPosition = 0;      // index of last placed cow
        
        for(int i = 1; i < n; i++){ // --imp-- start from 1 since first cow is already placed 
            if(stalls[i] - stalls[lastPlaceCowPosition] >= d){ // valid placement for distance d
                lastPlaceCowPosition = i;
                cowPlaced++;
            }
            if(cowPlaced >= totalCows){   // all cows placed successfully
                return true;
            }
        }
        return false;                     // not possible for this distance
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end()); // sort stall positions
        int n = stalls.size();
        int s = 1;                         // minimum possible distance
        int e = stalls[n-1] - stalls[0];   // maximum possible distance
        int ans = 0;
        
        while(s <= e){
            int mid = s + (e - s)/2;       // candidate minimum distance
            
            if(check(stalls,k,n,mid)){     // distance mid is feasible
                ans = mid;                 // store answer
                s = mid + 1;               // try for larger distance
            }
            else{
                e = mid - 1;               // reduce distance
            }
        }
        return ans;                        // largest minimum distance
    }
};
