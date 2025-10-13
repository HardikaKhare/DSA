class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            
            if(nums[mid]<nums[high]){
                if(nums[mid]<mini && nums[high]>=mini){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
                mini=min(nums[mid],mini);
            }else{
                if(nums[mid]>mini && nums[low]<=mini){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
                mini=min(nums[mid],mini);
            }
        }
        return mini;
    }
};