class Solution {
public:
    int findMin(vector<int>& nums) {
            // Code Here
     int n=nums.size();
        int mini=INT_MAX;
        int low=0;
        int high=n-1;
        int k=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<nums[high]){
                mini=min(mini,nums[mid]);
                high=mid-1;
            }else{
                mini=min(mini,nums[low]);
                low=mid+1;
            }
        }
        
        return mini;
    }
};