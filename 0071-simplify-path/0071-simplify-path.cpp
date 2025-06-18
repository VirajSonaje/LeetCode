class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string folder = "";

        for(char c: path){
            if(c == '/'){
                if(folder == "." || folder == ""){
                    //do nothing
                }
                else if( folder == ".."){
                    if(!st.empty()) st.pop();
                }
                else{
                    st.push(folder);
                }
                folder = "";
            }
            else{
                folder += c;
            }
        }

        if(folder == "." || folder == ""){
                    //do nothing
                }
                else if( folder == ".."){
                    if(!st.empty()) st.pop();
                }
                else{
                    st.push(folder);
                }

        string ans = "";

        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if(ans.length() == 0) return "/";
        return ans;
    }
};