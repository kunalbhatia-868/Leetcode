class MyHashSet {
public:
    vector<list<int>> mp;
    int size;
    MyHashSet() {
        size=100;
        mp.resize(size);
    }
    
    int hash(int key){
        return key%size;
    }
    
    list<int> :: iterator search(int key){
        int idx=hash(key);
        return find(mp[idx].begin(),mp[idx].end(),key);
    }
    
    void add(int key) {
        if(contains(key))return;
        
        int idx=hash(key);
        mp[idx].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key))return;
        
        int idx=hash(key);
        mp[idx].erase(search(key));
    }
    
    bool contains(int key) {
        int idx=hash(key);
        list<int> :: iterator it=search(key);
        if(it!=mp[idx].end()){
            return true;
        }
        return false;
    }
    
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */