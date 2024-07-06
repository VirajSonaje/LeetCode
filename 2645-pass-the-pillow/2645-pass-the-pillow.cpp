class Solution {
public:
    int passThePillow(int n, int time) {
        int rounds = time/(n-1);
        return rounds%2 ? (n - time%(n-1)) : (time%(n-1) +1);
    }
};