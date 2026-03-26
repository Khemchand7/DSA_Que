class Solution {
  public:
    int countWays(int n, int k) {
       
       if(n == 1) return k;
       
       //creating ans for n = 2
       int same = k*1;
       int diff = k * (k - 1);
       int total = same + diff;
       
       for(int i = 3; i <=n; i++){
           same = diff * 1;
           diff = total * (k - 1);
           total = same + diff;
       }
       return total;
        
    }
};