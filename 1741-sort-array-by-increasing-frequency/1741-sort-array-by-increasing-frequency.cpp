class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i: nums) freq[i]++;

        vector<pair<int, int>> sortedByValue;
        for(auto i: freq) sortedByValue.push_back({i.second, i.first});
        sort(sortedByValue.begin(), sortedByValue.end(), cmp);
        
        int idx =0;
        for(auto i: sortedByValue){
            int ctr = i.first;
            while(ctr--) nums[idx++] = i.second;
        }

        return nums;
    }
};