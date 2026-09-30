class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";

        vector<int> freq(128, 0);

        for (char ch : t)
            freq[ch]++;

        int start = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int ansStart = 0;

        for (int end = 0; end < s.size(); end++) {

            if (freq[s[end]] > 0)
                count--;

            freq[s[end]]--;

            while (count == 0) {

                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    ansStart = start;
                }

                freq[s[start]]++;

                if (freq[s[start]] > 0)
                    count++;

                start++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(ansStart, minLen);
    }
};