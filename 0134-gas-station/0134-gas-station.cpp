class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalgas = 0, totalcost = 0, curgas = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            totalgas += gas[i];
            totalcost += cost[i];
            
            curgas += gas[i]- cost[i];
            if(curgas < 0){
                ans= i+1;
                curgas = 0;
            } 
        }

        return (totalgas < totalcost) ? -1 : ans;
    }
};

// [1 ,2, 3, 4, 5]
// [3, ,4 ,5, 1 , 2]
// -2, -4, -6, -3, 0
// -2 -2 -2 3 3