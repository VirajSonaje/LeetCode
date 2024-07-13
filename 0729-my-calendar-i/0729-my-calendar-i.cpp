class MyCalendar {
public:
    map<int, int> calender;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto ub = calender.upper_bound(start);

        if(ub != calender.end() && (*ub).second < end) return false;
        calender[end] = start;
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */