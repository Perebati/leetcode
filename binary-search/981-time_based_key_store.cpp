//link: https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
private:
    unordered_map<string, map<int, string>> timeMap;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) { 
        timeMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = timeMap.find(key);
        if(it == timeMap.end()) return "";
        auto& inner = it->second;

        auto pos = inner.upper_bound(timestamp);

        if (pos == inner.begin()) return ""; 

        --pos;
        return pos->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */