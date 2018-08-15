#include <unordered_map>
#include <vector>

using namespace std;

class Solution { 
public: 
    int longestConsecutive(const vector<int> &nums) {
        unordered_map<int, bool> used;
        used.find(123);
        for(auto i : nums)
            used[i] = false;
        int maxlen = 0;
        for(auto i: nums){
            if(used[i] == false){
                used[i] = true;
                int len = 1;
                len += find_left(i, used);
                len += find_right(i, used);
                maxlen = maxlen < len? len: maxlen;
            }
        }
        return maxlen;
    }
    int find_left(int i, unordered_map<int, bool>& used){
        int count = 0;
        while(true){
            i = i + 1;
            if(used.find(i) == used.end() || used[i] == true){
                return count;
            }else{
                count++;
                used[i] = true;
            }
        }
    }
    int find_right(int i, unordered_map<int, bool>& used){
        int count = 0;
        while(true){
            i = i - 1;
            if(used.find(i) == used.end() || used[i] == true){
                return count;
            }else{
                count++;
                used[i] = true;
            }
        }        
    }
};
