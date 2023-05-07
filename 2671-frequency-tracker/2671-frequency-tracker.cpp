class FrequencyTracker {
public:
    unordered_map<int,int> mp;
    unordered_map<int,int> freq;
    
    FrequencyTracker() {
        mp.clear();
        freq.clear();
    }
    
    void add(int number) {
        if(mp.count(number)==0){
            mp[number]=1;
            freq[1]++;
        }
        else{
            freq[mp[number]]-=1;
            if(freq[mp[number]]==0){
                freq.erase(mp[number]);
            }
            
            mp[number]+=1;
            freq[mp[number]]+=1;  
        }
    }
    
    void deleteOne(int number) {
        if(mp.count(number)==0){
            return ;
        }
        else{
            mp[number]-=1;
            freq[mp[number]+1]-=1;
            if(freq[mp[number]+1]==0){
                freq.erase(mp[number]+1);
            }
            freq[mp[number]]+=1;
            if(mp[number]==0){
                mp.erase(number);
            }
        }

    }
    
    bool hasFrequency(int frequency) {
        return freq.count(frequency);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */