class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n) return -1;
        int low = 0, high = 1e9;

        while(low < high){
            int mid = low+ (high-low)/2;

            if(checkBouquets(bloomDay, m, k, mid)) high = mid;
            else low = mid+1;
        }
        return low;
    }


    bool checkBouquets(vector<int> &garden, int m, int k, int day){
        int bouquet = 0, n = garden.size();

        for(int i=0; i<n; i++){
            int count = 0; 

            while(i < n && count < k && garden[i] <= day){
                count++;
                i++;
            }

            if(count == k){
                bouquet++;
                i--;
            }

            if(bouquet >= m) return true;
        }

        return false;
    }
};