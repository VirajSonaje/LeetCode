class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<char> st;

        for(char c: s){
            if(c == ')'){
                string rev = "";
                while(st.top() != '('){
                    rev += st.top();
                    st.pop();
                }
                st.pop(); // remove the bracket

                for(char r: rev) st.push(r);
            }
            else{
                st.push(c);
            }
        }

        while(!st.empty()){
            ans=st.top() + ans;
            st.pop();
        }
        return ans;
    }
};