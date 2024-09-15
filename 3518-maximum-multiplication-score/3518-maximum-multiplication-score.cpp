class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<long long> ans(4, INT_MIN);
        for(long long num: b){
            ans[3] = max(ans[3], ans[2]+a[3]*num);
            ans[2] = max(ans[2], ans[1]+a[2]*num);
            ans[1] = max(ans[1], ans[0]+a[1]*num);
            ans[0] = max(ans[0], a[0]*num);
        }

        return ans[3];
    }
};