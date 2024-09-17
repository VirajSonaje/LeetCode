class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> combined = split(s1 + " " + s2);
        vector<string> ans;
        unordered_map<string, int> freq;
        for(string s: combined){
            freq[s]++;
        }

        for(auto word: freq){
            if(word.second == 1)ans.push_back(word.first);
        }
        return ans;
    }

    vector<string> split(string s){
        vector<string> ans;
        string temp = "";
        for(char c: s){
            if(c == ' '){
                ans.push_back(temp);
                temp = "";
            }
            else temp+=c;
        }
        if(temp != "") ans.push_back(temp);
        return ans;
    }
};