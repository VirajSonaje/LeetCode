class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        long rem = numerator;
        long quo =0;
        long den = denominator;
        string ans = "";
        if(rem < 0 ^ den <0) ans+="-";
        rem = abs(rem);
        den = abs(den);
        quo = rem/den;
        rem %= den;
        if(rem == 0) return ans+to_string(quo);
        ans += to_string(quo);
        ans+=".";
        rem*=10;
        unordered_map<long, int> mp;
        while(rem > 0){
            if(mp.count(rem) > 0){
                ans.insert(mp[rem], 1, '(');
                ans+=')';
                return ans;
            }
            mp[rem] = ans.length();
            quo = rem/den;
            ans+=to_string(quo);
            rem %= den;
            rem*=10;
        }
        return ans;
    }
};