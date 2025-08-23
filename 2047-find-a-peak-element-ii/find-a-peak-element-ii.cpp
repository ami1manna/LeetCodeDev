class Solution {
public:
    int findMax(vector<vector<int>>& arr, int mid) {
        int n = arr.size();

        int m = INT_MIN;
        int index = -1;

        for (int i = 0; i < n; i++) {
            if (m < arr[i][mid]) {
                m = arr[i][mid];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0;
        int m = mat[0].size();
        int high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int peak = findMax(mat, mid);
            cout << "mid" << m << "peak " << peak << endl;
            int left = (mid >= 1) ? mat[peak][mid - 1] : -1;
            int right = (mid <= m - 2) ? mat[peak][mid + 1] : -1;

            if (left < mat[peak][mid] && mat[peak][mid] > right) {
                return {peak, mid};
            } else if (left > mat[peak][mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};