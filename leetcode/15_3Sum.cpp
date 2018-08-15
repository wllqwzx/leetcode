#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0)
                break;
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int target = -nums[i];
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k] == target){
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(nums[j] == nums[j+1]) j++;
                    while(nums[k] == nums[k-1]) k--;
                    j++; k--;
                }else if(nums[j] + nums[k] < target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return res;
    }
};