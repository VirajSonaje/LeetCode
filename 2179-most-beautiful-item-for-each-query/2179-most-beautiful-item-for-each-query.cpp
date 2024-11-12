class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        sort(items.begin(), items.end());
        int n = items.size();
        int maxb = items[0][1];
        for(int i=0; i<n; i++ ){
            maxb = max(maxb, items[i][1]);
            items[i][1] = maxb;
        }

        for(int query: queries){
            vector<int> pr = {query, INT_MAX};
            auto num = upper_bound(items.begin(), items.end(), pr,
            [](const vector<int> &a, const vector<int> &b){
                return a[0] < b[0];
            });
            if(num == items.begin()){
                ans.push_back(0);    
            }
            else{
                num--;
                ans.push_back((*num)[1]);
            }
        }

        return ans;
    }
};