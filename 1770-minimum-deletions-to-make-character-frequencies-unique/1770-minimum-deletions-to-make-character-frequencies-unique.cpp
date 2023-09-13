class Solution {
public:
    int minDeletions(string s) {
        map<char, int> mp;
        map<int, int> mp2;
        int ans =0;
        for(char c: s)mp[c]++;
        for(auto i: mp){
                if(!mp2[i.second]) mp2[i.second]++;
                else{
                    while(mp2[i.second]){
                        ans++;
                        i.second--;
                    }
                    if(i.second > 0){
                        mp2[i.second]++;
                    }
                }
        }
        
        return ans;
    }
};