class Solution {
public:
    int myAtoi(string s) {
        int start = 0, sign = 1, n = s.size();
        int ans =0;
        while(s[start] == ' ') start++;
        
        if(start >= n) return 0;
        if(!isdigit(s[start]) && s[start] != '-' 
        && s[start] != '+') return 0;
        
        if(s[start] == '-') sign = -1, start++;
        else if(s[start] == '+') sign = 1, start++;

        while(start < n && isdigit(s[start])){
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && s[start]>'7')){
                return sign == -1? INT_MIN : INT_MAX;
            }

            ans = ans*10+ (s[start] - '0');
            start++;
        }

        return ans*sign;
    }
};