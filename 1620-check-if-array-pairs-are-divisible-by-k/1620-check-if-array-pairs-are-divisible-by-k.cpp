class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n ; i++) { 
            arr[i] %= k;
            if(arr[i] < 0) arr[i]+=k;
            mp[arr[i]]++;
        }
        for(auto m: mp) cout<<m.first<<" "<<m.second<<endl;
        if(mp[0] %2 != 0) return false;
        for(int i=1; i<=k/2; i++){
            if(mp[i] != mp[(k-i)]) return false;
        }
        return true;
    }
};