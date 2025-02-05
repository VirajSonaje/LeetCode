class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int ineq =0;
        int a =-1, b =-1;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] != s2[i]){
                ineq++;
                if(a== -1) a = i;
                else if(b== -1) b=i;
            } 
        }

        if(ineq == 0) return true;
        else if(ineq == 2 && s1[a] == s2[b] && s1[b] == s2[a]) return true;
        return false;
    }
};