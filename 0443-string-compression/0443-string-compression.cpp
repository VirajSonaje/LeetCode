class Solution {
public:
    int compress(vector<char>& chars) {
        int ansL =0;
        int n = chars.size();
        if(n == 1) return 1;
        int count = 1;
        char curr = chars[0];
        
        for(int i=1; i<n; i++){
            if(curr == chars[i]){
                count++;
            }
            else{
                chars[ansL++] = curr;
                if(count > 1)
                    for(char c: to_string(count)) chars[ansL++] = c;
                curr = chars[i];
                count = 1;
            }
        }
        chars[ansL++] = curr;
        if(count > 1)
            for(char c: to_string(count)) chars[ansL++] = c;
        return ansL;
    }
};