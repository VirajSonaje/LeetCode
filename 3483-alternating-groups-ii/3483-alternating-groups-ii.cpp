class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        
        for(int i=0; i<k-1; i++){
            colors.push_back(colors[i]);
        }
        int left =0;
        int right = 0;
        int n = colors.size();
        int ans = 0;
        while(right < n){
            if(right > 0 && colors[right] == colors[right - 1]){
                left = right;
            }
            if(right - left+1 == k){
                ans++;
                left++;
            }
            right++;
        }
        return ans;
    }
};