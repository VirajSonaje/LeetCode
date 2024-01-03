class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0;

        for(string s: bank){
            int laser = 0;
            for(char c: s) if(c=='1') laser++;
            if(laser > 0) {
                ans = ans + prev * laser;
                prev = laser;
            }
        }
        return ans;
    }
};