#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-2; i>=0; i--){
            bool find = false;
            int maxv = INT_MAX;
            int maxi = i;
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]<nums[j] && maxv>nums[j]){
                    maxv = nums[j];
                    maxi = j;
                    find = true;
                }
            }
            if(find == true){
                nums[maxi] = nums[i];
                nums[i] = maxv;
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};