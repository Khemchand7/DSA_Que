class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1; // i is used for indexing
        int j = 0; // position where unique element can exist
        while (i < nums.size()) {
            if (nums[i] == nums[j])
                i++;
            else
                nums[++j] =
                    nums[i++]; // pehle j increment hoga and then assignment
                               // hogi aur kyuki i par post increment hai to
                               // assignment ke bad value increase hogi i ki

            /*             if (nums[i] == nums[j]) {
                            i++;
                        } else {
                            j++;
                            nums[j] = nums[i];
                            i++;
                        } */ //same can also be written as shown
        }
        return j + 1; // kyuki hume return karna hai k=no. of unique elements
        // j agar 4 par khada hai o base indexing hoti hai to no. of unique
        // elements will be j+1=4+1=5
    }
};