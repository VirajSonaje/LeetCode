class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i=0; i<s.length()/k; i++){
            ans.push_back(s.substr(i*k, k));
        }
        if(s.length()%k){
            string t = s.substr(k*(s.length()/k));
            t += string(k- (s.length()%k), fill);
            ans.push_back(t);
        }
        return ans;
    }
};