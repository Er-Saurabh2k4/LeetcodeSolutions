class Solution {
public:

    // Merge two sorted parts: [s...mid] and [mid+1...e]
    void merged(int* arr, int s, int e) {

        int mid = s + (e - s) / 2;

        int len1 = mid - s + 1;
        int len2 = e - mid;

        int* first = new int[len1];
        int* second = new int[len2];

        // Copy left part
        int mainArrayIndex = s;

        for (int i = 0; i < len1; i++) {
            first[i] = arr[mainArrayIndex++];
        }

        // Copy right part
        mainArrayIndex = mid + 1;

        for (int i = 0; i < len2; i++) {
            second[i] = arr[mainArrayIndex++];
        }

        // Merge
        int index1 = 0;
        int index2 = 0;
        mainArrayIndex = s;

        while (index1 < len1 && index2 < len2) {

            if (first[index1] < second[index2]) {
                arr[mainArrayIndex++] = first[index1++];
            }
            else {
                arr[mainArrayIndex++] = second[index2++];
            }
        }

        // Remaining elements of first
        while (index1 < len1) {
            arr[mainArrayIndex++] = first[index1++];
        }

        // Remaining elements of second
        while (index2 < len2) {
            arr[mainArrayIndex++] = second[index2++];
        }

        delete[] first;
        delete[] second;
    }


    // Recursive Merge Sort
    void mergeSort(int* arr, int s, int e) {

        // Base case
        if (s >= e) {
            return;
        }

        int mid = s + (e - s) / 2;

        // Sort left half
        mergeSort(arr, s, mid);

        // Sort right half
        mergeSort(arr, mid + 1, e);

        // Merge both sorted halves
        merged(arr, s, e);
    }


    vector<int> sortArray(vector<int>& nums) {

        int s = 0;
        int e = nums.size() - 1;

        mergeSort(nums.data(), s, e);

        return nums;
    }
};