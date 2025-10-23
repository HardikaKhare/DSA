class Solution {
public:
    vector<int>merge(vector<int>&nums1, vector<int>& nums2){
        int n=nums1.size();
        int m=nums2.size();
        vector<int>merged;
        int left=0,right=0;
        while(left<n &&right<m){
            if(nums1[left]<nums2[right]){
                merged.push_back(nums1[left]);
                left++;
            }else{
                merged.push_back(nums2[right]);
                right++;
            }
        }
          while (left < n) {
        merged.push_back(nums1[left]);
        left++;
    }

    while (right < m) {
        merged.push_back(nums2[right]);
        right++;
    }

        return merged;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged=merge(nums1,nums2);
        int l=merged.size();
        if(l%2!=0){
            return merged[l/2];
        }else{
            return (merged[l/2 - 1] + merged[l/2]) / 2.0;
        }
    }
};