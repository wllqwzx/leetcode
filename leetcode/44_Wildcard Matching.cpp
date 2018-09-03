#include <vector>
#include <string>
using namespace std;

class Solution {
public:    
    bool isMatch(string& s, string& p) {
        int lens = s.size();
        int lenp = p.size();
        vector<vector<bool> > dp(lens+1, vector<bool>(lenp+1, false));
        dp[0][0] = true;
        for(int i=1;i<=lenp; i++){
            if(p[i-1] == '*') dp[0][i] = dp[0][i-1];
        }
        for(int i=1; i<=lens; i++)
            for(int j=1; j<=lenp; j++){
                if(p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1];
                }else{
                    if(s[i-1]==p[j-1]) dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = false;
                }
            }
        return dp[lens][lenp];
    }
};
