class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp; 
        for(int i: arr){
            mp[i] = 1;
        }
        int i=1;
        for(auto& m: mp){
            m.second = i;
            i++;
        }

        for(int i=0; i<arr.size(); i++){
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};