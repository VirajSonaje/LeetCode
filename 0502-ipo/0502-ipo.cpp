class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        map<int, vector<int>> mp;
        int n = profits.size();
        for(int i=0; i<capital.size(); i++) {
            mp[capital[i]].push_back(profits[i]);
        } 
        map<int, vector<int>>::iterator it;
        it = mp.begin();
        for(int i=0; i<min(k, n); i++){
            while(it->first <= w && it!=mp.end()){
                for(auto i: it->second) pq.push(i);
                it++;
            }
            if(pq.empty()) return w;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};