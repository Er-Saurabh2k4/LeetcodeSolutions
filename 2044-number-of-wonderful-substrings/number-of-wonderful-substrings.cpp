class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long long, long long> mp;
        mp[0] = 1;
        int cum_Xor = 0;
        long long ans = 0;
        for (char& ch : word) {
            int shift = ch - 'a'; // binary representation of ch
            cum_Xor ^= (1 << shift);
            ans += mp[cum_Xor]; // even case
            for (char ch1 = 'a'; ch1 <= 'j'; ch1++) {//odd case
                shift = ch1 - 'a';
                //cum xor ka xor saree character a to j karke check
                long long check_Xor = (cum_Xor ^ (1 << shift));
                ans += mp[check_Xor];
            }
            mp[cum_Xor]++;
        }
        return ans;
    }
};