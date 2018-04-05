#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
private:
    map<int, int> m;
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        for(int i:A) for(int j:B) m[i+j]++;
        int ans = 0;
        for(int i:C) for(int j:D) ans+=m[-(i+j)];
        return ans;
    }
};

int main(){
    return 0;
}