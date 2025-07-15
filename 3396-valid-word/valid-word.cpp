class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        set<char> vw = {'A','E','I','O','U','a','e','i','o','u'};
        if(n < 3){
            return false;
        }
        int v = 0;
        int c = 0;
        int d = 0;
        
        for(int i = 0 ; i < n ; i++){

            if(!isalnum(word[i])){
                return false;
            }

            else{
                // check vowel
                if(isdigit(word[i])){
                    d++;
                }
                else if(vw.find(word[i]) != vw.end()){
                    v++;
                }
                else{
                    c++;
                }
                // consonant
            }
            
        }
        if( v > 0 && c > 0){
            return true;
        }
        
            return false;
        

    }
};