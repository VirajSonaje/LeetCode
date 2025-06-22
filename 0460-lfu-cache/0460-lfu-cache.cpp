class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> data; //data - key val, freq
    unordered_map<int, list<int>> freqMap; // freq list keyvals
    unordered_map<int, list<int>::iterator> positions;//key to position in freqmap
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(!data.count(key)){
            return -1;
        }
        int val = data[key].first;
        int freq = data[key].second;
        freqMap[freq].erase(positions[key]);
        freqMap[freq+1].push_front(key);
        positions[key] = freqMap[freq+1].begin();
        data[key].second = freq+1;
        if(minFreq == freq && freqMap[freq].size() == 0 ) minFreq++;

        return data[key].first;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;
        
        if(get(key) != -1){
            data[key].first = value;
            return;
        }
        if(data.size() == capacity){
            int evictKey = freqMap[minFreq].back();
            positions.erase(evictKey);
            data.erase(evictKey);
            freqMap[minFreq].pop_back();
        }
        minFreq = 1;
        data[key] = {value, minFreq};
        freqMap[minFreq].push_front(key);
        positions[key] = freqMap[minFreq].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */