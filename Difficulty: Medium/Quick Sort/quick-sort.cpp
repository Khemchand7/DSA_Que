class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low < high){
            int pivotIndex = partition(arr,low,high);
            quickSort(arr,low,pivotIndex-1);
            quickSort(arr,pivotIndex+1,high);
            
        }
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int i = low;
        int j = low;
        int pivot = arr[high];
        
        while(i <= j && j < high){
            if(arr[j] > pivot){
                j++;
            }
            else{
                swap(arr[i],arr[j]);
                i++;
                j++;
            }
        }
        swap(arr[high],arr[i]); 
        return i;
    }
};
/*
3 4 7 6 5

4 1 3 7 9

1 3  4



*/