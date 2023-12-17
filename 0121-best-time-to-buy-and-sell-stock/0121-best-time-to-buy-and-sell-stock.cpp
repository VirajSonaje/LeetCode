class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxD =0 , minP = prices[0];
        
        
        for(int i=0; i< prices.size(); i++){
            if(minP > prices[i]){
                minP= prices[i];
            }
            if( maxD < (prices[i] - minP) ){
                maxD = prices[i] - minP;
            }
               
        }
        
        return maxD;
        }
};