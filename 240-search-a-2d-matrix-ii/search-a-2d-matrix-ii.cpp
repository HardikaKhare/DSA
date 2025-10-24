class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n = arr.size();
        int m = arr[0].size();
        int row = 0,col=m-1;
        while (row<n && col>=0) {
            if (arr[row][col] == target)
                return true;
            else if (arr[row][col] < target)
                row++;
            else
                col--;
        }
        return false;
    }
};