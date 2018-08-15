#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

//==========O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans;
        for(int i=0;i<len;i++){
            int t=1;
            int l = ans.size();
            for(int j=0;j<l;j++){
                if(nums[i]>nums[j]){
                    t = t>ans[j]+1?t:ans[j]+1;
                }
            }
            ans.push_back(t);
        }
        int max =0;
        for(int i:ans){
            max = max>i?max:i;
        }
        return max;
    }
};

//==========O(nlogn)
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int i:nums){
            auto iter = lower_bound(ans.begin(), ans.end(), i);
            if(iter == ans.end())
                ans.push_back(i);
            else
                *iter = i;
        }
        return ans.size();
    }
};


//==========

int main(){
    return 0;
}