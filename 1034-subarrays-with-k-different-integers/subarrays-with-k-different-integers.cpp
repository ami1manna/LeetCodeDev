class Solution {
public:
    int count(vector<int>& nums , int k){
        int l = 0;
        int r = 0;
        int cnt = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        while(r < n){
            // cout<< " l " << l<< " r  "<<r<<endl;
            int num = nums[r];
            mp[num]++;
            while(mp.size() > k){               
            // cout<<"map size" << mp.size()<<endl;
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }

            cnt +=  (r - l + 1);
            r++;
        }

        // cout<<" _____"<<cnt<<"________"<<endl;
        return cnt;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int le = count(nums , k); 
        int l = count(nums , k - 1);
           return le - l;  
       
    }
};