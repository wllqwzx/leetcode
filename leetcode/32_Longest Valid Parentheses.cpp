#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(const string& s) {
        int len = s.size();
        vector<int> dp(len+5, 0);
        for(int i=1; i<len; i++){
            if(s[i]=='('){
                dp[i] = 0;
            }else{
                if(dp[i-1]==0){
                    if(s[i-1]=='('){
                        int t = i-2>=0?dp[i-2]:0;
                        dp[i] = t+2;
                    }
                    else dp[i] = 0;
                }else{
                    if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='('){
                        int t = i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0;
                        dp[i] = dp[i-1]+2+t;
                    }
                    else dp[i] = 0;                    
                }
            }
        }
        int maxv = 0;
        for(auto i:dp) maxv = i>maxv?i:maxv;
        return maxv;
    }
};
