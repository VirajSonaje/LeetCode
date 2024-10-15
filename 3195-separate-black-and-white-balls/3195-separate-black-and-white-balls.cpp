class Solution {
public:
    long long minimumSteps(string s) {
        int one = 0;
        long long ans =0;
        for(char c: s){
            if(c == '1') one++;
            else ans+=one;
        }
        return ans;
    }
};