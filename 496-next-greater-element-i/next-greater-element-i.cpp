class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            int next=-1;
            for(int j=i+1;j<nums2.size();j++){
                if(nums2[j]>nums2[i]){
                    next=nums2[j];
                    break;
                }
            }
            mp.insert({nums2[i],next});
        }
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};