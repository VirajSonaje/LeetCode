class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> st;
        int sum =0;
        vector<int> ans(2);
        int sz = grid.size();
        for(int i =0; i<sz; i++){
            for(int n: grid[i]){
                cout<<n<<" ";
                sum+=n;
                if(st.count(n)){
                    sum-=n;
                    ans[0] = n;
                }
                st.insert(n);
            }
        }
        sz *= sz;
        ans[1] = ((sz *(sz+1))/2) - sum;
        return ans;
    }
};