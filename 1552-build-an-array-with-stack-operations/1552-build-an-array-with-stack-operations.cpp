class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int it = 0, N = target.size();
        for(int i = 1; i<=n; i++){
            if(i == target[it]){
                ans.push_back("Push");
                it++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if(it==N)break;
        }
        return ans;
    }
};