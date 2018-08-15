#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution{
public:
    double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
        int a = A.size();
        int b = B.size();
        if((a+b)%2==0){
            int k = (a+b)/2;
            double t1 = findKthLargest(A, 0, a, B, 0, b, k);
            double t2 = findKthLargest(A, 0 ,a ,B, 0, b, k+1);
            return (t1 + t2)/2;
        }else{
            int k = (a+b)/2 + 1;
            return findKthLargest(A, 0, a, B, 0, b, k);
        }
    }

    double findKthLargest(const vector<int>& A, int as, int ae, const vector<int>& B, int bs, int be, int k) {
        if(as>=ae) return double(B[bs+k-1]);
        if(bs>=be) return double(A[as+k-1]);
        int a_mid = (as+ae)/2;
        int b_mid = (bs+be)/2;
        int a1 = a_mid - as;
        int a2 = ae - a_mid -1;
        int b1 = b_mid - bs;
        int b2 = be - b_mid -1;
        if(A[a_mid]<B[b_mid]){
            if(k<=a1+b1+1){
                return findKthLargest(A, as, ae, B, bs, b_mid, k);
            }else{
                return findKthLargest(A, a_mid+1, ae, B, bs, be, k-a1-1);
            }
        }else if(A[a_mid]>B[b_mid]){
            if(k<=a1+b1+1){
                return findKthLargest(B, bs, be, A, as, a_mid, k);
            }else{
                double tt = findKthLargest(B, b_mid+1, be, A, as, ae, k-b1-1);
                return tt;
            }
        }else{
            if(k>=a1+b1+1 && k<=a1+b1+2){
                return double(A[a_mid]);
            }else if(k<=a1+b1){
                return findKthLargest(A, as, a_mid, B, bs, b_mid, k);
            }else{
                return findKthLargest(A, a_mid+1, ae, B, b_mid+1, be, k-a1-b1-2);
            }
        }
    }
};

int main(){
    Solution sol = Solution();
    vector<int> A;
    vector<int> B;
    A.push_back(4);
    B.push_back(1);
    B.push_back(2);
    B.push_back(3);
    printf("%f",sol.findMedianSortedArrays(A,B));
    return 0;
}