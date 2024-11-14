class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = 100000, mid;

        while(low < high){
            mid = low + (high-low)/2;
            if(verify(mid, quantities, n)) low = mid +1;
            else high = mid;
        }
        return low;
    }

    bool verify(int m, vector<int>& quantities, int n){
        int sum =0;
        for(int q: quantities){
            sum+=(int)ceil((q*1.0)/(m*1.0));
        }
        return sum > n;
    }
};