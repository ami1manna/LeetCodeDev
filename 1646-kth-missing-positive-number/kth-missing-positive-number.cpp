class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    
        int cnt = 0;
        int ptr = 0;
        int i = 1;
        while(cnt<=k){
            cout<<" " << i << " "<<endl;
            if(ptr < arr.size()  && arr[ptr] == i){
                ptr++;
            }
            else{
                cnt++;
            }
            if(cnt == k){
                return i;
            }
            i++;
         }
         return 0;   
    }
};