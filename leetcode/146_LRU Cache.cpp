#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    list<int> used; // STORE key
    unordered_map<int, pair<int, list<int>::iterator>> cache;   // STORE key-(value, iterOfUsed)
    int cap;
    
    void touch(unordered_map<int, pair<int, list<int>::iterator>>::iterator it){
        used.erase(it->second.second);
        used.push_back(it->first);
        it->second.second = prev(used.end());
    }


public:
    LRUCache(int capacity): cap(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if(it==cache.end()) return -1;
        touch(it);
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if(it==cache.end()){
            if(cache.size()<cap){
                used.push_back(key);
                cache[key] = {value, prev(used.end())};
            }else{
                int rm_key = used.front();
                used.pop_front();
                cache.erase(rm_key);
                used.push_back(key);
                cache[key] = {value, prev(used.end())};
            }
        }else{
            touch(it);
            cache[key].first = value;
        }
    }
};
