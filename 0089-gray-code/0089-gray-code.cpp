class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 1) return {0, 1};
        vector<int> ans(pow(2,n), 0);
        ans[1] = 1;
        for(int i=1; i<n; i++){
            int offset = pow(2,i);
            int idoffset = pow(2,i+1);
            for(int id = 0; id < pow(2,i); id++){
                ans[idoffset - 1 - id] = ans[id]+offset;
            }
        }
        return ans;
    }
};