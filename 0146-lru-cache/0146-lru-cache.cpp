class LRUCache {
public:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>:: iterator> lookup;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(lookup.find(key) != lookup.end()){
            cache.splice(cache.begin(), cache, lookup[key]);
            return lookup[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lookup.find(key) != lookup.end()){
            cache.splice(cache.begin(), cache, lookup[key]);
            lookup[key]->second = value;
        }
        else{
            if(cache.size() == this->capacity){
                lookup.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front({key, value});
            lookup[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */