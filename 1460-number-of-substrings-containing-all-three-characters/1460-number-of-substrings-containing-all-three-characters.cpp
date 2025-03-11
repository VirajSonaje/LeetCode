class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans =0;
        int right =0, left =0;
        vector<int> abc(3, 0);
        int n = s.length();

        while(right<n){
            abc[s[right]-'a']++;

            while(abc[0] > 0 && abc[1] > 0 && abc[2] > 0){
                ans+=n-right;
                abc[s[left]-'a']--;
                left++;
            }
            right++;
        }
        return ans;
    }
};