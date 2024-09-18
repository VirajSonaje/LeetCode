class Solution {
public:
    static bool comp(string a ,string b){
        return (a+b) > (b+a);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> snum;
        string ans = "";
        for(int n: nums){
            snum.push_back(to_string(n));
        }
        sort(snum.begin(), snum.end(), comp);
        if(snum[0] == "0") return "0";
        for(string s: snum) ans+=s;
        return ans;
    }
};