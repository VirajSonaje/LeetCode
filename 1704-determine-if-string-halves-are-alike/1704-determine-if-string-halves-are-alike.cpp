class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char> vows = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int c =0, n=s.length();
        for(int i=0; i<n/2; i++){
            if(vows.find(s[i]) != vows.end()) c++;
            if(vows.find(s[n-i-1]) != vows.end()) c--;
        }
        return c == 0;
    }
};