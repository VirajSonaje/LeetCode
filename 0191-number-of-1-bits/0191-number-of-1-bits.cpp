class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c=0;
        unsigned int x = 0x01;
        for(int i =0; i<32;i++){
            if((x&n) == 1){
                c++;
            }
        n = n>>1;
        }
        
        return c;
    }
};