class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s=0; 
       int n=nums.size();
       int e=n-1;
       while(s<=e){
        int mid=s+(e-s)/2;
        if(nums[mid]==target) return true;
         // Duplicates make it impossible to know
            // which side is sorted
            if(nums[s]==nums[mid] && nums[e]==nums[mid]){
                s++;
                e--;
            }
        //chec which part is sorted 
        //left part 
       else if(nums[s]<=nums[mid]){
            //nus[s]<=target is used to check repeated numbers
            if(nums[mid]>target && nums[s]<=target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        //right part 
        else{
            //nums[e]>= target is used to check for repeated number 
            if(nums[mid]<target && nums[e]>=target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
       }
       return false;
    }
};