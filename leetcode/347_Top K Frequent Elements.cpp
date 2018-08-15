#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i:nums) m[i]++;
        
        priority_queue<pair<int,int> > q;
        for(auto iter:m) q.push(pair<int,int>(iter.second, iter.first));
        
        vector<int> ans;
        for(int i = 0;i<k;i++){ans.push_back(q.top().second);q.pop();}
        return ans;
    }
};


int main(){
    return 0;
}