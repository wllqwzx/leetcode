#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        for(int i=0; i<256; i++) hash[i] = -1;
        int left = 0;
        int maxv = 0;
        for(int right=0; right<s.size(); right++){
            char c = s[right];
            if(hash[c] != -1){
                if(left<hash[c]+1)
                    left = hash[c]+1;
                hash[c] = right;
                maxv = maxv>=(right-left+1)?maxv:(right-left+1);
            }else{
                hash[c] = right;
                maxv = maxv>=(right-left+1)?maxv:(right-left+1);
            }
        }
        return maxv;
    }
};

