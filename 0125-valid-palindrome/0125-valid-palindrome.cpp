class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(char c: s){
            if(isalpha(c) || isdigit(c)) t+=tolower(c);
        }
        return isPal(t);
    }

    bool isPal(string s){
        for(int i=0; i<s.length()/2 ; i++){
            if(s[i] != s[s.length()-1-i]) return false;
        }
        return true;
    }
};