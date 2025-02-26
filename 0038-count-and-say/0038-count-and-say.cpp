class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for(int i=1; i<n; i++){
            string temp = "";
            char curr = s[0];
            int count =1;
            for(int j=1; j<s.length(); j++){
                if(s[j] == curr){
                    count++;
                }
                else{
                    temp+=to_string(count)+curr;
                    count = 1;
                    curr = s[j];
                }
            }
            temp+=to_string(count)+curr;
            s = temp;
        }

        return s;
    }
};