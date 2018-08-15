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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return head;
        else{
            ListNode *odd = head;
            ListNode *even = head->next;
            ListNode *cur = head;
            ListNode *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
                cur->next = temp->next;
                cur=temp;
            }
            cur = odd;
            while(cur->next!=NULL) cur=cur->next;
            cur->next = even;
            return odd;
        }
    }
};

//==========

int main(){
    return 0;
}