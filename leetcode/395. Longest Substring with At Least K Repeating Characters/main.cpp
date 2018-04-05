#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = int(s.length());
        int count[30] = {0};
        int ans = 0;
        for(int i=0; i<len; i++){
            count[s[i]-'a']++;
        }
        int st = 0;
        while(st<len){
            if(count[s[st]-'a'] !=0 && count[s[st]-'a']<k){
                st++;
            }else{
                int en = st;
                while(en<len && (count[s[st]-'a'] ==0 || count[s[en]-'a']>=k)){
                    en++;
                }
                if(en-st == len){
                    ans = ans<len?len:ans;
                }else{
                    string subs = s.substr(st, en-st);
                    int tt = longestSubstring(subs, k);
                    ans = ans<tt?tt:ans;
                }
                st = en;
            }
        }
        return ans;
    }
};


int main()
{   
    string ss = "aacbbbdc";
    Solution *so = new Solution();
    int ans = so->longestSubstring(ss, 2);
    printf("%d",ans);
    return 0;
}