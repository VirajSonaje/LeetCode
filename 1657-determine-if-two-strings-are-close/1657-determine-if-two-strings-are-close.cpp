class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        vector<int> w1v(26,0), w2v(26,0);
        for(char c: word1) w1v[c-'a']++;
        for(char c: word2) w2v[c-'a']++;

        for(int i=0; i<26; i++) if((bool)w1v[i] ^ (bool)w2v[i]) return false;
        sort(w1v.begin(), w1v.end());
        sort(w2v.begin(), w2v.end());
        
        return w1v == w2v;
    }
};