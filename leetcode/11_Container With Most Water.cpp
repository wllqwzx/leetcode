#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxv = 0;
        while(l<r){
            maxv = max(maxv, (r-l)*min(height[l], height[r]));
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return maxv;
    }
};
