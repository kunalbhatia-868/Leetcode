class MyHashMap {
public:
    vector<list<pair<int,int>>> mp;
    int size;
    
    MyHashMap() {
        size=100;
        mp.resize(100);
    }
    
    int hash(int key){
        return key%size;
    }
    
    list<pair<int,int>> :: iterator search(int key){
        int idx=hash(key);
        list<pair<int,int>> :: iterator it=mp[idx].begin();
        while(it!=mp[idx].end()){
            if(it->first==key){
                return it;
            }
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        remove(key);
        int idx=hash(key);
        mp[idx].push_back({key,value});
    }
    
    int get(int key) {
        list<pair<int,int>> :: iterator it =search(key);
        int idx=hash(key);
        if(it==mp[idx].end()){
            return -1;
        }
        else{
            return it->second;
        }
    }
    
    void remove(int key) {
        int idx=hash(key);
        list<pair<int,int>> :: iterator it =search(key);
        if(it!=mp[idx].end()){
            mp[idx].erase(search(key));        
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */