class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> ref;
        vector<vector<string>> ans;
        for(string s: strs){
            string t = s;
            sort(t.begin(), t.end());
            ref[t].push_back(s);
        
        }
        for(auto t: ref){
            ans.push_back(t.second);
        }
        return ans;
    }
};