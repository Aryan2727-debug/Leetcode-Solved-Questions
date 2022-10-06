class TimeMap {
    unordered_map<string, map<int,string>> A;
public:
    TimeMap() {
        A.clear();
    }
    
    void set(string key, string value, int timestamp) {
        A[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = A[key].upper_bound(timestamp);
        return it == A[key].begin() ? "" : prev(it)->second;
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */