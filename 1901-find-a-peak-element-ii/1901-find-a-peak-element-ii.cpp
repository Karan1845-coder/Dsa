class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Find column index of maximum element in middle row
            int col = 0;
            for (int j = 1; j < n; j++) {
                if (mat[mid][j] > mat[mid][col])
                    col = j;
            }

            int up = (mid > 0) ? mat[mid - 1][col] : -1;
            int down = (mid < m - 1) ? mat[mid + 1][col] : -1;

            if (mat[mid][col] > up && mat[mid][col] > down)
                return {mid, col};

            if (up > mat[mid][col])
                high = mid - 1;
            else
                low = mid + 1;
        }

        return {-1, -1};
    }
};