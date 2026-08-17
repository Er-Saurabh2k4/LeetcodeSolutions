class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = 0;

        for (int pile : piles) {
            maxi = max(maxi, pile);
        }

        return maxi;
    }

    long long calculateTotal(vector<int>& piles, int speed) {
        long long total = 0;

        for (int pile : piles) {
            total += (pile + speed - 1LL) / speed;
        }

        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = findMax(piles);

        while (s <= e) {
            int mid = s + (e - s) / 2;

            long long totalh = calculateTotal(piles, mid);

            if (totalh <= h) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return s;
    }
};