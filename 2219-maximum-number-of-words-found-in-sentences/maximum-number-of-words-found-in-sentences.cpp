class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;

        for (string sent : sentences) {
            int words = 1;

            for (char ch : sent) {
                if (ch == ' ') {
                    words++;
                }
            }

            maxi = max(maxi, words);
        }

        return maxi;
    }
};