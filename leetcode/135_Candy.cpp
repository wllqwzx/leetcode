#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> count;
        int n = ratings.size();
        for(int i=0;i<n;i++) count.push_back(1);
        bool find = true;
        while(find){
            find = false;
            for(int i=0; i<n-1; i++){
                if(ratings[i]<ratings[i+1] && count[i]>=count[i+1]){
                    count[i+1] = count[i]+1;
                    find = true;
                }
                if(ratings[i]>ratings[i+1] && count[i]<=count[i+1]){
                    count[i] = count[i+1]+1;
                    find = true;
                }
            }
            for(int i=n-1; i>0; i--){
                if(ratings[i]<ratings[i-1] && count[i]>=count[i-1]){
                    count[i-1] = count[i]+1;
                    find = true;
                }
                if(ratings[i]>ratings[i-1] && count[i]<=count[i-1]){
                    count[i] = count[i-1]+1;
                    find = true;
                }
            }
        }
        int ans = 0;
        for(auto i:count)
            ans +=i;
        return ans;
    }
};
