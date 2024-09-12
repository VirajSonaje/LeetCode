class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans =0;
        regex allow("^["+allowed+"]+$");
        for(string word: words){
            if(regex_match(word, allow))
                ans++;
        }

        return ans;
    }
};