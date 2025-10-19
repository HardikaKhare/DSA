class Solution {
public:
    int func(vector<int>&nums,int t,int high,int m){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            
            sum+=(nums[i]+m-1)/m;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int t) {
        int n=nums.size();
        int low=1;
        int high= *max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int a=func(nums,t,high,mid);
            if(a<=t){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};