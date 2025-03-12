class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)return "0";
        string ans = "";
        long rem = numerator;
        long quo = 0;
        long den = denominator;
        quo = rem/den;
        rem %= den;
        ans+=to_string(quo);
        if(!rem) return ans;
        ans+=".";
        bool flag = true;
        unordered_map<long, int> mp;
        while(rem){
            if(mp.count(rem) > 0){
                ans.insert(mp[rem], 1, '(');
                ans+=')';
                break;
            }

            mp[rem] = ans.length();
            rem*=10;
            ans+=to_string(rem/den);
            rem%=den;
        }
        return ans;
    }
};