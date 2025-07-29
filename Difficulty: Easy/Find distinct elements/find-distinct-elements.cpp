// User function Template for C++
int distinct(vector<int>& arr) {
    int n = arr.size();
    unordered_set<int>uset;
    
    for(auto num : arr){
        uset.insert(num);
    }
    
    return uset.size();
    
}