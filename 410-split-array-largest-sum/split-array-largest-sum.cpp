class Solution {
public:
    int maxsum(vector<int>& nums, int k,int m) {
        int n=nums.size();
        int split=1; int summ=0;
        for(int i=0;i<n;i++){
            if(nums[i]+summ<=m){
                summ+=nums[i];
            }else{
                split++;
                summ=nums[i];
            }
        }
        return split;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (maxsum(nums, k, mid) <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};