#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int a1,a2,a3;
        int minv = 99999999;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int dis = nums[i] + nums[j] + nums[k] - target;
                if(dis<0) dis = -dis;
                if(dis<minv){
                    a1=i;
                    a2=j;
                    a3=k;
                    minv = dis;
                }
                if(nums[i] + nums[j] + nums[k] - target == 0){
                    return target;
                }else if(nums[i] + nums[j] + nums[k] - target > 0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return nums[a1] + nums[a2] + nums[a3];
    }
};
