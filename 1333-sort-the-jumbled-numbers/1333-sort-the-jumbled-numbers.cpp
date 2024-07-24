class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // convert element to real decimal format
        // add to data structure that will sort and maintain the order
        // can use : map<int, vector>

        map<int, vector<int>> realValues;

        for(int i: nums){
            int real = convert(i, mapping);
            // cout<< real << " "<<endl;
            realValues[real].push_back(i);
        }
        int idx = 0;
        for(auto mp: realValues){
            for(int i: mp.second) nums[idx++] = i;
        }

        return nums;
    }

    int convert(int num, vector<int> &mapping){
        if(num == 0) return mapping[0];
        int newNum = 0;
        int multiplier = 1;
        while(num > 0){
            newNum += (mapping[num%10]*multiplier);
            multiplier *= 10;
            num /= 10;
        }
        return newNum;
    }
};