class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int x:nums){
            int digit=0;
            while(x>0){
                x/=10;
                digit++;
            }
            if(digit%2==0) cnt++;
        }
        return cnt;
    }
};


// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//         int count = 0;

//         for (int num : nums) {
//             if (to_string(num).length() % 2 == 0) {
//                 count++;
//             }
//         }

//         return count;
//     }
// };