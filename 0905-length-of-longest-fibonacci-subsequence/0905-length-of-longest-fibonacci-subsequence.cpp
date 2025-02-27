class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> nums; // map of number vs indexes
        for(int i =0; i<arr.size(); i++){
            nums.insert(arr[i]);
        }
        
        int ans =2;
        for(int i=0; i<arr.size()-1; i++){
            for(int j=i+1; j<arr.size(); j++){
               int temp =2, a = arr[i], b = arr[j];
                while(nums.count(a+b)){
                    int t = a+b;
                    a = b;
                    b = t;
                    temp++;
                }
                ans = max(temp, ans);        
            }
        }
        if(ans < 3) return 0;
        return ans;
    }
};