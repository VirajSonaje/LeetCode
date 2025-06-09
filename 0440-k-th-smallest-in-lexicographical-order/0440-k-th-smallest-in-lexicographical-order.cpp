class Solution {
public:
    int findKthNumber(long n, int k) {
        long num = 1;
        for(int i=1; i<k;){
            int jump = getJump(num, num+1, n);
            if(i+jump <= k){
                i+=jump;
                num++;
            }
            else{
                i++;
                num*=10;
            }
        }
        return num;
    }

    int getJump(long a, long b, long &n){
        int jump = 0;
        while(a <= n){
            jump += min(b, n+1) - a;
            a*=10;
            b*=10;
        }
        return jump;
    }
};