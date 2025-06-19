class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans =low;
        while(low<high){
            int mid = low + (high-low)/2;
            long cost1 = findCost(nums, cost, mid);
            long long cost2 = findCost(nums, cost, mid+1);

            if(cost1 > cost2){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return findCost(nums, cost, low);
    }

    long long findCost(vector<int> &nums, vector<int>& cost, int n){
        long long ans =0L;
        for(int i=0; i<nums.size(); i++){
            ans+= 1L*abs(nums[i] - n)*cost[i];
        }
        return ans;
    }
};