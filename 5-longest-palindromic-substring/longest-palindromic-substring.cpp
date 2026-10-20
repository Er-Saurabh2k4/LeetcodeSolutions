class Solution {
public:
string expand(string s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        l--;
        r++;
    }
    return s.substr(l + 1, r - l - 1);
}
    string longestPalindrome(string s) {
         string ans = "";

    for (int i = 0; i < s.size(); i++) {
        string a = expand(s, i, i);       // Odd length
        string b = expand(s, i, i + 1);   // Even length

        if (a.size() > ans.size()) ans = a;
        if (b.size() > ans.size()) ans = b;
    }

    return ans;
    }
};