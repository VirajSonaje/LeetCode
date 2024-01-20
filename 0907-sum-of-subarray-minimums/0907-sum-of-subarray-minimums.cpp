class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size() , mod = 1000000007;
        long long int ans =0;
        vector<long long int> left(n), right(n,n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            left[i] = st.empty() ? i+1 : i-st.top();
            st.push(i);
        }
        st = stack<int>();
        for(int i=n-1; i >=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            right[i] = st.empty() ? n-i : st.top()-i;
            st.push(i);
        }
        for(int i=0; i<n; i++){
            ans = (ans + arr[i] * left[i] * right[i]) %mod;
        }
        
        return ans;
    }
};