#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

//==========
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 1;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];

        }
    }
};

//==========

int main(){
    return 0;
}