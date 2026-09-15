class Solution {
public:
    bool isPalindrome(int x) {
        int copy=x;
         long int y=0;
        while(copy!=0){
            if(copy<0){
                return false;
            }
            int dig=copy%10;
        copy/=10;
        y=(y*10)+dig;
        }
        
        if(y==x) return true;
        else{
            return false;
        }
        
    }
};