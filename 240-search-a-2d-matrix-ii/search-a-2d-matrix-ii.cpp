class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n = arr.size();
        int m = arr[0].size();

        for (int i = 0; i < n; i++) {
            if (arr[i][0] <= target && target <= arr[i][m - 1]) {
                int low = 0, high = m - 1;

                while (low <= high) {
                    int mid = (low + high) / 2;

                    if (arr[i][mid] == target)
                        return true;
                    else if (arr[i][mid] > target)
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
            }
        }

        return false;
    }
};