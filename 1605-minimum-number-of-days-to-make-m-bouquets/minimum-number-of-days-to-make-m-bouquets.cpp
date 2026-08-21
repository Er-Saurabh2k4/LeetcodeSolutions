class Solution {
public:
    bool possible(vector<int>& bloomDay,int day, int m, int k){
        int cnt=0;
        int bDay=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day) cnt++;
            else{
                bDay+=cnt/k;
                cnt=0;
            }
        }
         bDay+=cnt/k;
            return bDay>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL * k* 1LL;
        if(val>bloomDay.size()) return -1;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            mini=min(bloomDay[i],mini);
            maxi=max(bloomDay[i],maxi);
        }
        int low=mini;
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};