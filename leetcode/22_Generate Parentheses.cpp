#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

//==========
class Solution {
public:
    void rec(vector<string> &s, int left, int right, string str){
        if(left>0){
            rec(s, left-1, right, str+string("("));
        }
        if(right>left){
            rec(s, left, right-1, str+string(")"));
        }
        if(left==0 && right==0){
            s.push_back(str);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> s;
        rec(s, n, n, string(""));
        return s;  
    }
};
//==========

int main(){
    return 0;
}