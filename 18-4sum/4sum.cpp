class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                set<long long>hashset;
                for(int k=j+1;k<n;k++){
                        long long left=(long long) target-(long long)nums[i]-nums[j]-nums[k];
                        if(hashset.find(left)!=hashset.end()){
                             vector<int>temp={nums[i],nums[j],nums[k],(int)left};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                        hashset.insert(nums[k]);
                        }
                    }
                }
            
        
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};