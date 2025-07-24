class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            int curr = nums[i];
                
                if(!dq.empty() && dq.front() <=  i - k) {
                    dq.pop_front();
                }

                // if(dq.size() >= k){
                //     dq.pop_front();
                // }

                while(!dq.empty() && nums[dq.back()] <= curr){
                    dq.pop_back();
                }
                
                dq.push_back(i);


            
            if(i >=  k - 1){
                int m = dq.front();
                 ans.push_back(nums[m]);
            }

            // for(int i  : dq){
            //     cout << " " << i ;
            // }
            // cout<<endl;
        }

        return ans;
    }
};