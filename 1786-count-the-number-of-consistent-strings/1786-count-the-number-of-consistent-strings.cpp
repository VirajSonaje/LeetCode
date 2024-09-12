class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
vector<int> count(26, 0);
        for (char c : allowed)
        {
            count[c-'a'] = 1;
        }

        int ans = 0;
        for (string s : words)
        {
            bool ok = true;
            for (char ch : s)
            {
                if (count[ch-'a'] == 0) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans++;
        }

        return ans;
    }
};