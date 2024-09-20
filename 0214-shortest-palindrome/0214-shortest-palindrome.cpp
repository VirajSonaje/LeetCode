class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length() < 2) return s;
        int n = s.length();
        int j=0;
        for(int i=0; i<n; i++){
            if(s[j] == s[n-i-1])j++;
        }
        if(j == n) return s;
        string rs = s.substr(j,n);
        reverse(rs.begin(), rs.end());
        return rs + shortestPalindrome(s.substr(0,j)) + s.substr(j);
    }
};