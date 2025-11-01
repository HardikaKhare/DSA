class Solution {
public:
int atmost(vector<int>& s,int k){
        int n=s.size();
        int left=0;
        int res=0;
        unordered_map<int,int>mpp;
          for (int right = 0; right < n; right++) {
            mpp[s[right]]++;

            while (mpp.size() > k) {
                mpp[s[left]]--;
                if (mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }

            res += (right - left + 1);
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& s, int k) {
        int ans= atmost(s, k) - atmost(s, k-1);
        return ans;
    }
};