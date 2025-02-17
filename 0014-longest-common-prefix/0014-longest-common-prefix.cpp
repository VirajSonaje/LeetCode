class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ptr = 0;
        int maxlen =0;
        bool flag = false;
        for(string s: strs) maxlen = max(maxlen, (int)s.length());
        for(ptr =0; ptr < maxlen; ptr++){
            char curr = strs[0][ptr];
            for(int i=0; i<strs.size(); i++){
                if(strs[i][ptr] != curr){
                    flag = true;
                    break;
                }           
            }
            if(flag) break;
        }

        return strs[0].substr(0, ptr);
    }
};