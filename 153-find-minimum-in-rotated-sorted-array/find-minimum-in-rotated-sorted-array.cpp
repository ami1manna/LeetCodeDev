class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;
        int smallest = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;
            // left half sorted

            if (nums[low] <= nums[mid]) {
                smallest = min(smallest , nums[low]);
                low = mid + 1;
                
            } else {
                    smallest = min(smallest , nums[mid]);
                    high = mid - 1;
                }
            }
        
        return smallest;
    }
};