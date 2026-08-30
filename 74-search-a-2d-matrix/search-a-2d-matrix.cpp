class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // considering 2D matrix into a virtual 1D array

        int rows = matrix.size();
        int cols = matrix[0].size();

        if(matrix.empty() || matrix[0].empty()) return false;

        int low = 0;
        int high = (rows*cols) - 1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            int midValue = matrix[mid/cols][mid%cols];

            if(target == midValue)
                return true;
            if(target > midValue)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};