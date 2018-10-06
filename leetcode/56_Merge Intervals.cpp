#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<int> s, e;
        for(auto& i:intervals){
            s.push_back(i.start);
            e.push_back(i.end);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        vector<Interval> res;
        int s_num = 0;
        int left;
        int i=0,j=0;
        while(i<s.size() && j<e.size()){
            if(s[i]<=e[j]){
                if(s_num==0) left = s[i];
                s_num++;
                i++;
            }else{
                s_num--;
                if(s_num==0) res.push_back(Interval(left, e[j]));
                j++;
            }
        }
        if(j<e.size()){
            res.push_back(Interval(left, e[e.size()-1]));
        }
        return res;
    }
};