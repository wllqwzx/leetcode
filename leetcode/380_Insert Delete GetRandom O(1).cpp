#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <random>

using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> m;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.count(val)) return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!m.count(val)) return false;
        int last_pos = nums.size() - 1;
        int target_pos = m[val];
        nums[target_pos] = nums[last_pos];
        m[nums[target_pos]] = m[val];
        m.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

int main(){
    return 0;
}