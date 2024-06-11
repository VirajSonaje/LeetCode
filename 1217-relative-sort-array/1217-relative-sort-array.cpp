class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for(int i: arr1) mp[i]++;
        int idx =0;
        for(int i: arr2){
            while(mp[i]--) arr1[idx] = i, idx++;
        }
        for(auto i: mp)
        {
            if(i.second >0)
            while(mp[i.first]--) arr1[idx] = i.first, idx++;
        }
        return arr1;
    }
};