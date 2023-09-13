class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> a (n, 1);
        for(int i=1; i<n;i++){
            if(r[i] > r[i-1]) a[i] = a[i-1]+1;
        }

        for(int i=n-2; i>=0;i--){
            if(r[i] > r[i+1]) a[i] = max(a[i+1]+1, a[i]);
        }
        int v = 0;
        for(int i: a) v+=i;
        return v;
    }
};