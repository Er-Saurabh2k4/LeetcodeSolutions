class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size();

        int cnt_max = -1;
        int index = -1;

        for(int i = 0; i < m; i++) {
            int cnt_ones = 0;

            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 1) {
                    cnt_ones++;
                }
            }

            if(cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }

        return {index, cnt_max};
    }
};