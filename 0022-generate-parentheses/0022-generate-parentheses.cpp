class Solution {
public:
    void gen(int op, int cl, vector<string> &ans, string a, int n){
        if(op == n){
            while(cl<n) {
                a+=")";
                cl++;        
            }
            ans.push_back(a);
            return;
        }
        gen(op+1, cl, ans, a+"(", n);

        if(cl<op){
            gen(op, cl+1, ans, a+")", n);
        }


    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string a;
        gen(0,0, ans, a, n);
        return ans; 
    }
};