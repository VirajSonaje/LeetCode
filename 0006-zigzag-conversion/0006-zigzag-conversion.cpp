class Solution {
public:
    string convert(string s, int numRows) {
    
    if(numRows == 1) return s; 
    vector<string> cipher(numRows, "");
    string ans = "";

    for(int i=0; i<s.size(); i++){
        cipher[passThePillow(numRows, i)] += s[i];
    }

    for(string s: cipher) ans+= s;

    return ans;

    }

    int passThePillow(int n, int time) {
        int rounds = time/(n-1);
        return rounds%2? (n-1 - time%(n-1)) : (time%(n-1));
    }
};