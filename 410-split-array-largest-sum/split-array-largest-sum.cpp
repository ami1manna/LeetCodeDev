class Solution {
public:
    int findSub(vector<int>& nums, int maxSum) {
        int count = 1;
        int sum = 0;

        for (auto i : nums) {

            if (sum + i <= maxSum) {
                sum += i;
            } else {
                sum = i;
                count++;
            }
        }

        return count;
    }
    int findSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        return sum;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = findSum(nums);
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            int sub = findSub(nums, mid);
            if (sub <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};