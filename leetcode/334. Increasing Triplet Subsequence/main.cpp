#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m = INT_MAX;
        int k = INT_MAX;
        for(int i:nums){
            if(i<=m) m=i;
            else if(i<=k) k=i;
            else return true;
        }
        return false;
    }
};


int main(){
    return 0;
}