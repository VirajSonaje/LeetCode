class Solution {
public:
    int romanToInt(string s) {
        map<char, int> numerals;
        numerals.insert(pair<char, int>('I', 1));
        numerals.insert(pair<char, int>('V', 5));
        numerals.insert(pair<char, int>('X', 10));
        numerals.insert(pair<char, int>('L', 50));
        numerals.insert(pair<char, int>('C', 100));
        numerals.insert(pair<char, int>('D', 500));
        numerals.insert(pair<char, int>('M', 1000));
        
        int value =0 ;
        for(int i=0; i<s.length(); i++){
            if(numerals[s[i+1]]>numerals[s[i]]){
                value += (numerals[s[i+1]]-numerals[s[i]]);
                i++;
            }
            else{
                value+= numerals[s[i]];
            }
        }
        
        return value;
    }
};