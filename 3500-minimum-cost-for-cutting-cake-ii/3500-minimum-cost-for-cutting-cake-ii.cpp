class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        long long ans = 0;
        long long horDiv =1, verDiv = 1;
        priority_queue<pair<int,int>> pq; 

        for(int h: horizontalCut) pq.push({h, 'h'});
        for(int v: verticalCut) pq.push({v, 'v'});

        while(!pq.empty()){
            auto nextCut = pq.top();

            if(nextCut.second == 'h'){
                ans+= (nextCut.first * verDiv);
                horDiv++;
            }
            else{
                ans+= (nextCut.first * horDiv);
                verDiv++;
            }

            pq.pop(); 
        }

        return ans;
    }
};