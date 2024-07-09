class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int currentfinish = 0, currentstart = customers[0][0];

        for(auto customer: customers){
            currentstart = max(customer[0], currentfinish);
            currentfinish = currentstart + customer[1];
            ans+= (currentfinish - customer[0]);
        }

        return (double)ans/customers.size();
    }
};