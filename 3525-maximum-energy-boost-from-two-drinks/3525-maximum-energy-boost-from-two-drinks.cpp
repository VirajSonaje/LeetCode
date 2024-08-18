class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        
        long long curA=0,  curB=0, prevA=0, prevB=0;

        for(int i=0; i<n; i++){
            curA = max(prevA + energyDrinkA[i], prevB);
            curB = max(prevB + energyDrinkB[i], prevA);
            prevA = curA;
            prevB = curB;
        }
        return max(curA, curB);
    }
};