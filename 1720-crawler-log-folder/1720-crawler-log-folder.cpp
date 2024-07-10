class Solution {
public:
    int minOperations(vector<string>& logs) {
        int levels = 0;

        for(string log: logs){
            if(levels > 0 && log[1] == '.'){
                levels--;
            }
            else if(isdigit(log[0]) || isalpha(log[0])){
                levels++;
            }
        }

        return levels;
    }
};