#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++){
            while(1<=nums[i] && nums[i]<=len && nums[i]-1 != i && nums[nums[i]-1] != nums[i]){
                //swap
                int t = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = t;
            }
        }
        for(int i=0; i<len; i++){
            if(nums[i]-1 != i)
                return i+1;
        }
        return len+1;
    }
};

