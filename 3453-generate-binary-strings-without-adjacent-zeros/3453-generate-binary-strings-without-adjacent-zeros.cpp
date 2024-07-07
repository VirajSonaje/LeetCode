class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans = {"0", "1"};
        if(n==1) return ans;
        
        for(int i=1; i<n; i++){
            vector<string> curr;
            for(int j=0; j<ans.size(); j++){
                if(ans[j][0] == '0') curr.push_back("1"+ans[j]);
                else {
                    curr.push_back("1"+ans[j]);
                    curr.push_back("0"+ans[j]);
                }
            }
            
            ans.clear();
            ans = curr;
        }
        
        return ans;
    }
};