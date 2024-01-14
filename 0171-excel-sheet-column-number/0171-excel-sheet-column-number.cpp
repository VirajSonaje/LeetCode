class Solution {
public:
    int titleToNumber(string columnTitle) {
        int col=0;
        for(int i=0; i<columnTitle.length(); i++){
            col*=26;
            col += (columnTitle[i]-'A'+1);
        }
        return col;
    }
};