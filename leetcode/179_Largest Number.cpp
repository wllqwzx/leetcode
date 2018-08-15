#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

//==========
struct my_prior{
	bool operator()(string x, string y) const 
	{
        int lenx = x.length();
        int leny = y.length();
        int index = 0;
        int indey = 0;
        int basex = 0;
        int basey = 0;
        while(true){
            if(x[index]<y[indey])
                return true;
            else if(x[index]>y[indey])
                return false;
            else{
                index++;
                indey++;
            }
            if(index==lenx && indey == leny)
                return true;
            if(index==lenx){
                index = basex;
                basey = indey;
            }
            if(indey==leny){
                indey = basey;
                basex = index;
            }
        }
        return true;
	}
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        priority_queue<string, vector<string>, my_prior> q;
        for(int i:nums){
            string t = to_string(i);
            q.push(t);
        }
        string ans;
        bool nonzero = false;
        while(!q.empty()){
            string t = q.top();
            if(t.compare(string("0"))==0){
                if(nonzero!=false)
                    ans.append(t);
            }else{
                nonzero = true;
                ans.append(t);
            }
            q.pop();
        }
        if(ans.compare(string(""))==0)
            return string("0");
        return ans;
    }
};
//==========

int main(){
    return 0;
}