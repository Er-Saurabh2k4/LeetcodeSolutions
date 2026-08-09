class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        // Why only j >= 0 is checked again after while loop?
        // Because if j < 0, nums2 is completely finished.
        // But if i >= 0, the remaining elements of nums1 are already in the correct position.
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};