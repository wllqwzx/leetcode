#include <vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int target, int left, int right){
        if(left>right) return -1;
        int mid = (left+right)/2;
        if(nums[mid] == target) return mid;
        
        if(nums[left]<=nums[mid]){
            if(nums[left]<=target && target<nums[mid])
                return solve(nums, target, left, mid-1);   
            else
                return solve(nums, target, mid+1, right);
        }else{
            if(nums[mid]<target && target<=nums[right])
                return solve(nums, target, mid+1, right);
            else
                return solve(nums, target, left, mid-1);
        }
    }
    
    int search(vector<int>& nums, int target) {
        return solve(nums, target, 0, nums.size()-1);
    }
};