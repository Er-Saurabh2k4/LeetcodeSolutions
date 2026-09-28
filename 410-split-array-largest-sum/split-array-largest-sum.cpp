class Solution {
public:
int countSubarray(vector<int>& nums,int maxSum){
    int subArray=1;
    int curSum=0;
    for(int i=0;i<nums.size();i++){
        if(curSum+nums[i]<=maxSum){
            curSum+=nums[i];
        }
        else{
            subArray++;
            curSum=nums[i];
        }
    }
    return subArray;
}
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0LL);
        while(low<=high){
            long long mid=low+(high-low)/2;
            int subarr=countSubarray(nums,mid);
            if(subarr>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};