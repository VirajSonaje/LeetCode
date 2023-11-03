class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        else if(x>=0 && x<10) return true;
        else {
         long rev = 0, compute = x;
            while(compute>0){
                rev = rev*10 + (compute%10);
                compute /= 10;
            }
            if (rev == x){
                return true;
            }
            else return false;
        }
    }
};