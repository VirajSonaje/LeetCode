class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        vector<int> dp(n+1, 0);
        for(int i=0; i<n; i++) jobs[i] = {endTime[i], startTime[i], profit[i]};

        sort(jobs.begin(), jobs.end());
        // for(auto j :jobs) 
        for(int i=0; i< n; i++){
            int lastJob = upper_bound(jobs.begin(), jobs.begin()+i, jobs[i][1], 
            [](int time, const auto &job){
                return time < job[0];
            }) - jobs.begin();
            // cout<<jobs[lastJob][0]<<" "<< jobs[lastJob][1]<<" "<<jobs[lastJob][2]<<endl;
            dp[i+1] = max(dp[i], dp[lastJob] + jobs[i][2]);
        }
        // for( auto i:  dp) cout<< i << " ";
        return dp[n];
    }
};