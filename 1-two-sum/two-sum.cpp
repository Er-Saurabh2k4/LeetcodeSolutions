class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int need=target-nums[i];
            if(mp.find(need)!=mp.end()){
                return {mp[need],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
//mp.end()

//already exists internally in every unordered_map.

//It is a built-in STL function that returns a special iterator called the end iterator.