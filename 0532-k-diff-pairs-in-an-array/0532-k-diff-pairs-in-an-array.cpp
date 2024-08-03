class Solution {
public:
    int twoPointerMethod(vector<int>& nums, int k) {
        int i = 0;
        int j = 1;
        sort(nums.begin(), nums.end()); // sort karne ki wajah se diff always be
                                        // gretaer than 0;
        set<pair<int, int>> ans;
        while (j < nums.size()) {
            int diff = nums[j] - nums[i];
            if (diff == k) {
                ans.insert({nums[i], nums[j]});
                i++, j++;
            } else if (diff > k)
                i++; // diff jyada hai k se to j ki taraf jaenge i will increase
                     // and distance will decrease as sorted
            else
                j++; // diff kam hai k se to j ko aage badaenge jisse diff
                     // badega

            if (i == j)
                j++; // jab i==j tha apne aap ko bhi consider kar rha tha   e.g.
                     // 1,3,1,5,4 expected 1  but is giving 4 as
            // o/p so solved that issue
        }
        return ans.size();
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////

    int binarySearch(vector<int>& nums, int start, int target){
        int end = nums.size()-1;
        int mid = start + (end-start)/2;
        while(start<=end){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return -1;
    };

    int usingBinarySearch(vector<int>& nums, int k){
        sort(nums.begin(),nums.end());
        set<pair<int,int>>ans;
        for(int i=0;i<nums.size();i++){//diff=a[j]-a[i] or a[j]=k+a[i] jahan khade hai wo a[i] aur uske right me binary search target=k+a[i] dhund le to wo pair ho jaega of diff = k;
            if(binarySearch(nums,i+1,nums[i]+k)!= -1){
                ans.insert({nums[i],nums[i]+k});
            }
        }
        return ans.size();
    }

    int findPairs(vector<int>& nums, int k) {
        //return twoPointerMethod(nums, k);
        return usingBinarySearch(nums,k);
    }
};