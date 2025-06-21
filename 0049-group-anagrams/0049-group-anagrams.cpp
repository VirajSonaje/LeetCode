class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(string s: strs){
            string st= s;
            sort(st.begin(), st.end());

            mp[st].push_back(s);
        }
        
        for(auto anagram: mp){
            vector<string> temp;
            ans.push_back(anagram.second);
        }

        return ans;
    }
};