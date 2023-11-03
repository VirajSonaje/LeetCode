class Solution {
public:
    int reverse(int x) {
        int limit_max = INT_MAX / 10;
        int rev = 0;
        bool flag = false;
        if(x == INT_MIN) return 0;
        if(x<0){
            flag = true;
            x *= -1;
        }
        int compute = x;
        while(compute>0){
            if(rev>limit_max) return 0;
            else if(rev == limit_max){
                if(flag && compute%10 >8) return 0;
                else if(!flag && compute%10>7) return 0;
                else{
                    rev = rev*10 + compute%10;
                    compute/=10;
                } 
            }
            else{
            rev = rev*10 + compute%10;
            compute/=10;
            }
            
        }
        if(flag) return rev*(-1);
        else return rev;
    }
};