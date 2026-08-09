class Solution {
public:

    // CHANGE 1: merged() now returns count
    int merged(int *arr, int s, int e) {

        int mid = s + (e - s) / 2;

        int len1 = mid - s + 1;
        int len2 = e - mid;

        int *first = new int[len1];
        int *second = new int[len2];

        int mainArrayIndex = s;

        for (int i = 0; i < len1; i++) {
            first[i] = arr[mainArrayIndex++];
        }

        mainArrayIndex = mid + 1;

        for (int i = 0; i < len2; i++) {
            second[i] = arr[mainArrayIndex++];
        }

        int index1 = 0;
        int index2 = 0;
        mainArrayIndex = s;

        // CHANGE 2: count reverse pairs BEFORE merging
        int count = 0;

        for (int i = 0; i < len1; i++) {

            while (index2 < len2 &&
                   (long long)first[i] > 2LL * second[index2]) {
                index2++;
            }

            count += index2;
        }

        // Your original merge code
        index1 = 0;
        index2 = 0;

        while (index1 < len1 && index2 < len2) {

            if (first[index1] <= second[index2]) {
                arr[mainArrayIndex++] = first[index1++];
            }
            else {
                arr[mainArrayIndex++] = second[index2++];
            }
        }

        while (index1 < len1) {
            arr[mainArrayIndex++] = first[index1++];
        }

        while (index2 < len2) {
            arr[mainArrayIndex++] = second[index2++];
        }

        delete[] first;
        delete[] second;

        // CHANGE 3: return count
        return count;
    }


    // CHANGE 4: mergeSort() now returns count
    int mergeSort(int *arr, int s, int e) {

        if (s >= e)
            return 0;

        int mid = s + (e - s) / 2;

        int count = 0;

        count += mergeSort(arr, s, mid);
        count += mergeSort(arr, mid + 1, e);

        // CHANGE 5: add reverse pairs found during merge
        count += merged(arr, s, e);

        return count;
    }


    int reversePairs(vector<int>& nums) {

        // CHANGE 6: call our mergeSort
        return mergeSort(nums.data(), 0, nums.size() - 1);
    }
};