class Solution {
public:
    long long coloredCells(int n) {
        unsigned long long en = n;
        return 1 + 2 * (en-1) * (en);
        
    }
};