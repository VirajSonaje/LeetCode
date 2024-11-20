class Solution {
public:
    int takeCharacters(string s, int k) {
        // Question transforms to find maximum length subarray where a, b, c are 
        //  strictly less than totalcount of char(a or b or c) - k
        vector<int> freq(3, 0);
        for(char c: s) freq[c-'a']++;
        if(freq[0] < k || freq[1] < k || freq[2] < k) return -1;

        string temp = "";
        int left =0;
        vector<int> count(3, 0);
        int max_len = 0;
        for(int right =0; right<s.size(); right++){
            count[s[right]-'a']++;

            while((freq[0] -k < count[0]) || (freq[1] -k < count[1]) || (freq[2] -k < count[2])){
                count[s[left]-'a']--;
                left++;
            }

            if((freq[0] -k >= count[0]) && (freq[1] -k >= count[1]) && (freq[2] -k >= count[2])){
                // for(int c: count) cout<<c<<" ";
                // cout<<"r = "<<right<<" "<<"l = "<<left;
                // cout<<endl;
                max_len = max(max_len, right-left+1);
            }
        }

        return s.size() - max_len;
    }
};