#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int sum = 0;
        int index = 0;
        for(int i=0; i<gas.size(); i++){
            sum += (gas[i] - cost[i]);
            total += (gas[i] - cost[i]);
            if(sum < 0){
                sum = 0;
                index = i+1;
            }
        }
        return total<0? -1:index;
    }
};