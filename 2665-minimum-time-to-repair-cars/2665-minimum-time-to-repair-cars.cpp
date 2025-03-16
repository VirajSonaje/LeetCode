class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0, right = (long long)*max_element(ranks.begin(), ranks.end())*cars*cars;
        long long ans = right;
        while(left <= right){
            long long mid = left+(right-left)/2;

            if(satisfy(ranks, mid, cars)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }

    bool satisfy(vector<int> &ranks, long long time, int cars){
        long long count = 0;
        for(int r: ranks){
            count += floor(sqrt(time/r));
        }
        return count >= cars;
    }
};