class Solution {
public:
    int numberOfChild(int n, int k) {
        if(n == 1) return 0;
        if(n == 2) return k%n;
        bool direction = (k/(n-1)) % 2 == 0;
        // cout<<direction<<endl;
        // cout<< k%(n-1) << " "<< n-1 - (k%n-1);
        if(direction) return k%(n-1);
        else return n-1 - (k%(n-1));
    }
};