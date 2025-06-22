class Solution {
public:
    string decodeString(string s) {
        int i=0;
        return helper(s, i);
    }

    string helper(string& s, int& i){
        string ans; 
        while(i<s.length() && s[i] != ']'){
            // cout<<i<<endl;
            if(!isdigit(s[i])){
                ans+=s[i];
                i++;
            }
            else{
                int n=0; 
                while(i < s.length() && isdigit(s[i])){
                    n = n*10 + s[i]-'0';
                    i++;
                }
                i++; 
                string t = helper(s, i);
                i++;

                while(n-- > 0){
                    ans+=t;
                }
            }
        }
        return ans;
    }
};