#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
private:
    vector<int> cur;
    vector<int> orig;

public:
    Solution(vector<int> nums) {
        cur.assign(nums.begin(), nums.end());
        orig.assign(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        cur.clear();
        cur.assign(orig.begin(), orig.end());
        return cur;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_shuffle(cur.begin(), cur.end());
        return cur;
    }
};

int main(){
    int li[3] = {1,2,3};
    vector<int> tt(li, li+3);
    Solution ss = Solution(tt);
    ss.reset();
    ss.shuffle();
    ss.shuffle();
    return 0;
}