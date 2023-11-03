class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> m; 
        m[')'] ='(';
        m['}'] = '{';
        m[']'] = '[';

        for(char c: s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else if(c == ')' || c == '}' || c == ']'){
                if(st.size() >0 && m[c] == st.top())st.pop();
                else return false;
            }

        }

        if(st.size() == 0) return true;
        return false;

    }
};