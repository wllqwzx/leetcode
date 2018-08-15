#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <queue>
#include <set>

using namespace std;


class Solution {
private:
    priority_queue<int> pq;
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        for(vector<int> v:matrix){
            for(int i:v){
                pq.push(i);
                if(pq.size()>k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};


int main(){
    return 0;
}