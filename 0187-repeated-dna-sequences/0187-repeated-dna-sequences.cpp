class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};
        map<string, int> sequences;
        vector<string> ans;
        for(int i=0; i<s.size() - 9; i++){
            sequences[s.substr(i, 10)]++;
        }
        for(auto seq: sequences){
            if(seq.second > 1) ans.push_back(seq.first);
        }

        return ans;
    }
};