class Solution {
public:
    void sub(vector<int>&val, vector<vector<int>>&ans,int idx,vector<int>& nums) {
        if(idx==nums.size()){
            ans.push_back(val);
            return;
        }
          sub(val, ans, idx + 1, nums);
           val.push_back(nums[idx]);
        sub(val, ans, idx + 1, nums);
        val.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>val;
        vector<vector<int>>ans;
        sub(val,ans,0,nums);
        return ans;
    }
};