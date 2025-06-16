class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        while(l < r){
            int mid = l + (r-l)/2;
            if(canEat(piles, h, mid)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }

        return l;
    }

    bool canEat(vector<int> &piles, int h, int k){
        int time =0;

        for(int x: piles){
            time+= (x/k);
            if(x%k) time++;
        }

        return h >= time;
    }
};