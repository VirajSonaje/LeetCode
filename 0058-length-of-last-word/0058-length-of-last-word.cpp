class Solution {
public:
    int lengthOfLastWord(string s) {
        int i,count =0;
        int flag =0;
        for(int i = s.length()-1;i>=0;i--){
            
            if(s[i]!=' '){
               count++;
                flag=1;
            }
            else if(flag){
                break;
            }
            
        }
        return count;
    }
};