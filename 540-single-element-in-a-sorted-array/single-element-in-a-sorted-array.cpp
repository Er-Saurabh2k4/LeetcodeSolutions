class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            //observation: pair occur then one index is odd and other is even 
            if(mid%2==1) mid--;
            if(nums[mid]==nums[mid+1]){
                s=mid+2;
            }
            else{
                e=mid;
            }
        }
        return nums[s];
    }
};