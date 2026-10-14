class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long ans = 0;
        int sign = 1;

        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Process digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            ans = ans * 10 + digit;

            // Handle overflow
            if (sign * ans >= INT_MAX) return INT_MAX;
            if (sign * ans <= INT_MIN) return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};