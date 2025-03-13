class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> sweep(n+1, 0);
        int k=0;
        int sum =0;
        for(int i=0;i<n;i++){
            sum += sweep[i];
            sweep[i] =0;
            if(sum < nums[i]){
                if(k == queries.size()) return -1;
                auto query = queries[k];

                if(query[1] >= i){
                    if(query[0] <= i) sum+=query[2];
                    else sweep[query[0]]+=query[2];

                    sweep[query[1]+1]-=query[2];
                }
                k++;
                i--;
            }
        }
        return k;
    }
};