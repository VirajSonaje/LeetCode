class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int pf =0;
        int pb = height.size()-1;
        int maxA = (pb-pf)*min(height[pb],height[pf]);
        
        for(int i=0; i<height.size(); i++){
            int d = pb- pf;
            if(d == 0){
                break;
            }
            if((d-1)*min(height[pb-1],height[pf]) > maxA){
                maxA = (d-1)*min(height[pb-1],height[pf]);
                pb--;
            }
            else if((d-1)*min(height[pb],height[pf+1]) > maxA){
                maxA = (d-1)*min(height[pb],height[pf+1]);
                pf++;
            }
            else{
                if(height[pf]> height[pb]){
                    pb--;                  
                }
                else{
                    pf++;
                }
                
            }
            
        }
        return maxA;
    }
};