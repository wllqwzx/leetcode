#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        vector<int> maxL;
        vector<int> maxR;
        int max = height[0];
        for(int i=0; i<height.size(); i++){
            max = max>height[i]?max:height[i];
            maxL.push_back(max);
        }
        
        max = height[height.size()-1];
        for(int i=height.size()-1; i>=0; i--){
            max = max>height[i]?max:height[i];
            maxR.push_back(max);
        }
        reverse(maxR.begin(), maxR.end());
        
        int ans = 0;
        for(int i=1; i<height.size()-1; i++){
            int max1 = maxL[i-1];
            int max2 = maxR[i+1];
            int max_min = max1 > max2?max2:max1;
            if(max_min>height[i])
                ans += (max_min - height[i]);
        }
        return ans;
    }
};

