class Solution {
public:
    int rev=0;
    int reverse(int x) {
        while(x!=0){
             int bit=x%10;
// So before multiplying by 10, the code checks:
// If rev > INT_MAX / 10, then rev * 10 will already be too big (overflow).
// If rev < INT_MIN / 10, then rev * 10 will already be too small (underflow).
             if(rev>INT_MAX/10 || rev<INT_MIN/10){
                return 0;
             }
        rev = (rev * 10) +bit;
        x/=10;
        }
        return rev;
    }
};
