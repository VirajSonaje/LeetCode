class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans =0, n = candidates.size();
        for(int i=0; i<32; i++){
            int temp =0;
            for(int candidate : candidates){
                if((candidate & (1<<i))) temp++;
            }
            ans = max(temp, ans);
        }
        return ans;
    }
};