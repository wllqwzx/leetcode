#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        int con[1000][1000] = {0};
        int h = matrix.size();
        int w = matrix[0].size();
        bool flag = true;
        while(flag==true){
            flag = false;
            for(int i=0;i<h;i++)
                for(int j=0;j<w;j++){
                    if(i-1>0 && matrix[i-1][j]<matrix[i][j]){
                        if(con[i][j]<con[i-1][j]+1){
                            con[i][j] = con[i-1][j]+1;
                            flag = true;
                        }
                    }
                    if(j-1>0 && matrix[i][j-1]<matrix[i][j]){
                        if(con[i][j]<con[i][j-1]+1){
                            con[i][j] = con[i][j-1]+1;
                            flag = true;
                        }
                    }
                    if(i+1<h && matrix[i+1][j]<matrix[i][j]){
                        if(con[i][j]<con[i+1][j]+1){
                            con[i][j] = con[i+1][j]+1;
                            flag = true;
                        }
                    }
                    if(j+1<w && matrix[i][j+1]<matrix[i][j]){
                        if(con[i][j]<con[i][j+1]+1){
                            con[i][j] = con[i][j+1]+1;
                            flag = true;
                        }
                    }
                }
        }
        int ans = 0;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++){
                if(con[i][j]>ans)
                    ans = con[i][j];
            }
        return ans+1;
    }
};


int main(){
    return 0;
}