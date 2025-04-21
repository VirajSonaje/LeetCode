class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mindiff = 0;
        long long maxdiff = 0;
        long long count =0;
        for(int i: differences){
            count +=i;
            mindiff = min(mindiff, count);
            maxdiff = max(maxdiff, count);
        }
        //cout<<maxdiff<<" "<<mindiff;
        if(abs(maxdiff - mindiff) > abs(upper - lower)){
            return 0;
        }
        return abs(upper - lower) + 1 - abs(maxdiff - mindiff);
    }
};