class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> st;
        for(auto i:nums){
            st[i]++;
        }
        for(auto it : st){
            if(it.second==1){
                return it.first;
            }
        }
        return -1;
    }
};