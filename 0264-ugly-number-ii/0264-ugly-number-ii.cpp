class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        set<long long> s;
        pq.push(1);
        for(int i=1; i<n; i++){
            long long cur = pq.top();
            pq.pop();
            if(s.find(cur*2) == s.end())s.insert(cur*2), pq.push(cur*2);
            if(s.find(cur*3) == s.end())s.insert(cur*3), pq.push(cur*3);
            if(s.find(cur*5) == s.end())s.insert(cur*5), pq.push(cur*5);
        }

        return pq.top();
    }
};