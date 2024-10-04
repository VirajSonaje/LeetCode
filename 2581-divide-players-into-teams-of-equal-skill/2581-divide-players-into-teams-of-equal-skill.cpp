class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long target = 0, sum =0;
        long long ans = 0;
        for(int i : skill) sum+=i;
        target= sum/(skill.size()/2);

        unordered_map<int, int> mp;
        for(int i=0; i<skill.size(); i++){
            if(mp[target - skill[i]]){
                ans+= (skill[i]*(target - skill[i]));
                mp[target - skill[i]]--;
                sum-= skill[i];
                sum-= target - skill[i];
            }
            else{
                mp[skill[i]]++;
            }
        }
        return sum ? -1 : ans;
    }
};