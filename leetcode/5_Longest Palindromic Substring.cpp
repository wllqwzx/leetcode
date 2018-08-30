#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(1,1));

        int maxv = 1;
        int ind = 0;
        for(int i=1; i<len; i++){
            if(s[i]==s[i-1]){
                dp[i].push_back(2);
                if(maxv<2){ maxv = 2; ind = i; }
            }
            for(auto c:dp[i-1]){
                if(i-1-c >= 0){
                    if(s[i-1-c] == s[i]){
                        dp[i].push_back(c+2);
                        if(maxv<c+2){ maxv=c+2; ind = i; }
                    }
                }
            }
        }
        string ans = "";
        for(int i=ind-maxv+1; i<=ind; i++) ans += s[i];
        return ans;
    }
};