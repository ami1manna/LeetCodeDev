class Solution {
public:
    int findDays(vector<int>& weights , int capacity){
        int n = weights.size();
        int days = 1;
        int loadedW = 0;
        for(int i = 0 ; i < n ; i++){

            // loadedW += weights[i];
            if(loadedW + weights[i] > capacity){
                loadedW = 0 ;
                days++;
            }
            
                loadedW += weights[i];
            
        }
        // cout<<days<<endl;
        return days;
    }
    int findSum(vector<int>& weights) {
        int sum = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
            sum += weights[i];
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

    int shipWithinDays(vector<int>& weights, int days) {

        cout<<findDays(weights , 15) <<endl;
        int low = findMax(weights);
        int high = findSum(weights);
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            cout<< mid <<endl;
            
            if(findDays(weights , mid) <= days){
                high = mid - 1;
                ans = mid;
            }
            else{

                low = mid + 1;
            }
        }

    return ans;
    }
};