class Solution {
public:
    int getLucky(string s, int k) {
        string sum;
        for(auto ch: s)sum+=to_string(ch-'a'+1);
        while(k--){
            int temp =0;
            for(auto ch: sum){
                temp+=(ch-'0');
            }
            sum = to_string(temp);
        }
        return stoi(sum);
    }
};