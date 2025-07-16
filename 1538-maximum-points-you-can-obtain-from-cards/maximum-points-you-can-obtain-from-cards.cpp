class Solution {
public:
    int findSum(vector<int>& cardPoints, int start , int k){
        int sum = 0;
        int off = start;
        int n =  cardPoints.size();
        cout<<"______"<<n<<"______"<<endl;

        for(int i = 0 ; i < k ; i++){
            start = (off +  i)%n;
            cout<<" "<< start <<" ";
            sum+= cardPoints[start];
        }
        cout<<endl<<sum<<endl;
        cout<<"____________"<<endl;
        return sum;
    }

    int maxScore(vector<int>& cardPoints, int k) {
    //  brute 
        // int n = cardPoints.size();
        // int l = 0;
        
        // int sumMax = 0;

        // for(int i = n - k ; i <= n ; i++){
            
        //     sumMax = max(sumMax , findSum(cardPoints, i , k));
            
        // }

        // cout<<sumMax<<endl;
        // return sumMax;

        // optimal
        int n = cardPoints.size();
        int l = 0 ;
        int r = n -1;
        int sum = findSum(cardPoints , l , k);
        int sumMax = sum;
        for(int i = k - 1 ; i >= 0 ; i--){

            sum -= cardPoints[i];
            sum += cardPoints[r];
            r--;
            sumMax = max(sumMax , sum);
       }

       return sumMax;
    }
};