class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long int additions = 0;
        for (int i = (int)ceil(log2(k)) - 1; i >= 0; i--) {
            long long int lidx = 1LL << i;
            // cout<<lidx << " "<< ridx <<" "<<k << endl; 
            if(k > lidx){
                k-= lidx;
                additions+=operations[i];
            }
        }

        return 'a'+(additions%26);
    }
};