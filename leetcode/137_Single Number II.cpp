#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = sizeof(int)*8;
        int *appear = new int[size];
        for(int i=0; i<size; i++) appear[i] = 0;
        for(auto i:nums){
            for(int t=0; t<size; t++){
                appear[t] += (i&1);
                i = (i>>1);
            }
        }
        int base = 1;
        int ans = 0;
        for(int i=0; i<size; i++){
            if(appear[i]%3==1){
                ans += base;
            }
            base *= 2;
        }
        return ans;
    }
};