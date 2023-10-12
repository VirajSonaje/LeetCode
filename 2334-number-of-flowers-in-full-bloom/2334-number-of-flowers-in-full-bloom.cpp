class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<long long int, int> mp;
        long long int minf = 1000000005, maxf = -1;
        for(auto f : flowers){
            mp[f[0]]++;
            minf = minf>f[0]?f[0]:minf;
            mp[f[1]+1]--;
            maxf = maxf<f[1]+1?f[1]:maxf;
            
        }
        int prev =0;
        for(auto i = mp.begin(); i!=mp.end(); i++){
            i->second+=prev;
            prev = i->second;
            // cout<<i->first<<" "<<i->second<<endl;
        }
        cout<<endl;
        vector<int> ans;
        for(int p: people){
            if(p < minf || p > maxf) {
                ans.push_back(0);
                // cout<<p<<" "<<0<<endl;
            }
            else{
                auto k = mp.lower_bound(p);
                if(k->first > p) k--;
                // cout<<k->first<<" "<<k->second<<endl;
                ans.push_back(k->second);
            }
            
        }
        return ans;
    }
};