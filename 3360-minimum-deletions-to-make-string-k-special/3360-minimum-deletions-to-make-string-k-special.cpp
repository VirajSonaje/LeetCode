class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0); 
        for(char c: word){
            freq[c-'a']++;
        }
        sort(freq.begin(), freq.end());
        int ans =INT_MAX; 
        int deletions =0;
        for(int i=0; i<26; i++){
            int temp = deletions;
            for(int j=i+1; j<26; j++){
                if(freq[i] + k < freq[j]){
                    temp +=(freq[j]- freq[i]-k);
                }
            }
            ans = min(temp, ans);
            deletions+=freq[i];
        }

        return ans;
    }

    /// a = 4, b = 2, c = 1 
    /// k = 0 -> 3

};