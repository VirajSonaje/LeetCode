class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        //// w w w b b b w b w b b w
        /////1 2 3 3 3 3 4 4 5 5 5 6
        int n = blocks.size();
        vector<int> prefix(n+1, 0);
        int ans =INT_MAX;
        for(int i=0; i<n; i++){
            if(blocks[i] == 'W') prefix[i+1] = prefix[i]+1;
            else prefix[i+1] = prefix[i];
        }

        int left =0; int right = k;
        for(right; right<=n; right++, left++){
            if(prefix[right] - prefix[left] < ans){
                ans = prefix[right] - prefix[left];
            }
        }

        return ans;    
    }
};