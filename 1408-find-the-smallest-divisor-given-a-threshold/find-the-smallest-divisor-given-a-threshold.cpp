class Solution {
public:
    int countB(vector<int>& bloomDay, int divisor) {

        int n = bloomDay.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil(bloomDay[i]/(double)divisor);
        }

        return sum;
    }

    int findMax(vector<int>& bloomDay) {
        int ans = INT_MIN;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++) {
            ans = max(ans, bloomDay[i]);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = findMax(nums);
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if(countB(nums , mid) <= threshold){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
         
        }

        return ans;
    }
};