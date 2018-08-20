#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> cur;
        DFS(candidates, res, cur, 0, target);
        return res;
    }
    
    void DFS(vector<int>& candidates, vector<vector<int> > &res, vector<int> &cur, int start, int target){
        if(target < 0) return;
        if(target ==0){
            res.push_back(cur);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            cur.push_back(candidates[i]);
            DFS(candidates, res, cur, i, target-candidates[i]);
            cur.pop_back();
        }
    }
};
