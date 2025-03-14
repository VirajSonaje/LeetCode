class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left =1, right =*max_element(candies.begin(), candies.end());
        int n=candies.size();
        int ans =0;
        while(left<=right){
            int mid = left+(right-left)/2;
            
            long long ch = 0;
            
            for(int i=0; i<n; i++){
                ch += (candies[i]/mid);
            }
        
            //cout<<mid<<" "<<ch<<endl;
            if(ch >= k){
                left = mid+1;
                ans = mid;
            } 
            else right = mid-1;
        }
        return ans;
    }
};