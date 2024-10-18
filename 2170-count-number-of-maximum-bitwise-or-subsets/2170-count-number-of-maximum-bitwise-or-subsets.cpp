class Solution {
public:
    // int countMaxOrSubsets(vector<int>& nums) {
    //     vector<int> counts(32, 0);
    //     int ans = 1;
    //     for(int n: nums){
    //         int a = n;
    //         int i=0;
    //         while(a > 0){
    //            if(a>>i & (0x01)) {
    //             counts[i]++;
    //            }
    //            a=a>>i;
    //            i++;
    //         }    
    //     }
    //     bool flag = false;
    //     for(int i=0; i<32; i++){
    //         cout<<i << " "<<counts[i]<<endl;
    //         if(counts[i] > 0) ans*=counts[i], flag = true;
    //     }
    //     if(flag) return ans;
    //     return 0;
    // }
        void backtrack(const vector<int> &nums, int index, int currentOR, int maxOR, int &count)
    {
        if (currentOR == maxOR)
        {
            count++;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            backtrack(nums, i + 1, currentOR | nums[i], maxOR, count);
        }
    }

    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxOR = 0;

        // Step 1: Compute the maximum OR
        for (int num : nums)
        {
            maxOR |= num;
        }

        int count = 0;
        // Step 2: Backtrack to count the subsets
        backtrack(nums, 0, 0, maxOR, count);

        return count;
    }
};