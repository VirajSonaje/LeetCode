class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //round robin with twist
        unordered_map<char, int> mp;
        int maxFreq = 0;
        for(char c: tasks){
            mp[c]++;
            maxFreq = max(maxFreq, mp[c]);
        }
        int modeElements =0;
        for(auto m: mp){
            if(m.second == maxFreq) modeElements++;
        }
        int time = (maxFreq - 1)*(n+1) + modeElements;

        return max(time, (int)tasks.size());
    }
};