class SeatManager {
private:
    int minres;
    priority_queue<int,vector<int>, greater<int>> pq;
public:
    SeatManager(int n) {
        minres = 1;
    }
    
    int reserve() {
        if(pq.empty())
        return minres++;
        else{
            int seat = pq.top();
            pq.pop();
            return seat;
        }
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber == minres){
            minres--;
        }
        else pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */