class Solution {
public:
    int search(vector<int>& a, int target) {
        int n=a.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(a[mid]==target){
                return mid; 
            }
            if(a[mid]>=a[low]){
                if(a[mid]>target && target>=a[low]){
                    high=mid-1;
                }else{
                   low=mid+1;
                }
            }
            else {
                if(a[mid]<target && target<=a[high]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};