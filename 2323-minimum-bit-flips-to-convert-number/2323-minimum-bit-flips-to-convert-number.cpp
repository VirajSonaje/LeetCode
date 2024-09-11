class Solution {
public:
    int minBitFlips(int start, int goal) {
        start = start ^ goal;
        int ans =0;
        while(start >0){
            ans+= (start & 0x01);
            start = start>>1;
        }

        return ans;
    }
};