class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        long long ans =0;
        for(int i: happiness){
            pq.push(i);
        }
        int children =0;
        while(children < k){
            int chosen = pq.top();
            pq.pop();
            if(chosen > children) chosen -= children;
            else chosen =0;
            ans+=chosen;
            children++;
        }

        return ans;
    }
};