class Solution {
public:
    string frequencySort(string s) {
         unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        vector<pair<char, int>> v;
        for (auto& p : freq) v.push_back(p);

       
        auto cmp= [&](pair<char, int>a, const pair<char, int>b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        };
 sort(v.begin(), v.end(),cmp);
        string ans;
        for (auto& p : v) ans.append(p.second, p.first);

        return ans;
    }
};