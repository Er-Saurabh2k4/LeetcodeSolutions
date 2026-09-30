class Solution {
public:
    vector<int> ans;
    vector<pair<int, int>> v;

    void mergeSort(int l, int r) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergeSort(l, mid);
        mergeSort(mid + 1, r);

        vector<pair<int, int>> temp;

        int i = l;
        int j = mid + 1;
        int rightSmaller = 0;

        while (i <= mid && j <= r) {
            if (v[j].first < v[i].first) {
                temp.push_back(v[j]);
                rightSmaller++;
                j++;
            } 
            else {
                ans[v[i].second] += rightSmaller;
                temp.push_back(v[i]);
                i++;
            }
        }

        while (i <= mid) {
            ans[v[i].second] += rightSmaller;
            temp.push_back(v[i]);
            i++;
        }

        while (j <= r) {
            temp.push_back(v[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++)
            v[l + k] = temp[k];
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        ans.resize(n, 0);
        v.resize(n);

        for (int i = 0; i < n; i++)
            v[i] = {nums[i], i};

        mergeSort(0, n - 1);

        return ans;
    }
};