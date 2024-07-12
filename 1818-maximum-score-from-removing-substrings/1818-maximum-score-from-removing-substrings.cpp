class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(s.size() == 1) return 0;
        string look;
        int points, ans;
        if(x > y) look = "ab";
        else look = "ba";
        if(look == "ab") points = x;
        else points = y;
        ans = getScore(s, look, points);

        look = look == "ab" ? "ba" : "ab";
        points = look == "ab" ? x : y;

        ans+= getScore(s, look, points);

        return ans;
    }

    int getScore(string &s, const string &look,const int &points){
        int total = 0;
        string result = "";
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(!st.empty()){
                string check;
                check.push_back(st.top());
                check.push_back(s[i]);
                if(check == look){
                    total+=points;
                    st.pop();
                }
                else st.push(s[i]);
            }
            else st.push(s[i]);
        }

        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        s = result;
        return total;
    }
};