class Solution {
public:
    int maxDistance(string s, int k) {
        int distH = 0, distV = 0;
        int ans =0;
        int i=0;
        for(char c: s){
            if(c == 'N') distV++;
            else if(c == 'S') distV--;
            else if(c == 'W') distH--;
            else distH++;
            // cout<<distV<<" "<<distH<<endl;
            ans = max(ans, min(abs(distH) + abs(distV) + 2*k, i+1));
            i++;
        }
        return ans;
    }
};