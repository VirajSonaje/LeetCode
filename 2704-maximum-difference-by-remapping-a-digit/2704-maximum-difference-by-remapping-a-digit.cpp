class Solution {
public:
    int minMaxDifference(int num) {
        string n = to_string(num);
        char fst;
        for(char c: n)if(c != '9') {
            fst = c;
            break; 
        }
        string nNum = "";
        int ans = 0;
        for(char c: n){ //MAX
            if(c == fst) nNum+='9';
            else nNum+=c;
        }
        ans+=stoi(nNum);
        nNum = "";
        for(char c: n)if(c != '0') {
            fst = c;
            break; 
        }
        for(char c: n){ //MIN
            if(c == fst) nNum+='0';
            else nNum+=c;
        }
        ans-=stoi(nNum);
        return ans;
    }
};