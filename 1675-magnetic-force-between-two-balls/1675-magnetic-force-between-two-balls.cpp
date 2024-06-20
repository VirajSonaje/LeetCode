class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 1, high = position[n-1] - position[0];
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int lastPos = position[0];
            int balls = 1;

            for(int i=1; i<n; i++){
                if(position[i] - lastPos >=mid){
                    lastPos = position[i];
                    balls++;
                }
            }
            if(balls >= m){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        return ans;
    }
};