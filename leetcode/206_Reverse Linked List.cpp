#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode *pre = nullptr;
        ListNode *mid = head;
        ListNode *post = head;

        while(post->next != nullptr){
            post = post->next;
            mid->next = pre;
            pre = mid;
            mid = post;
        }
        post -> next = pre;
        return post;
    }
};