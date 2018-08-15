#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

//===============================
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }else if(head->next->next == NULL){
            ListNode *tail = head -> next;
            tail->next = head;
            head->next = NULL;
            return tail;
        }else{
            ListNode *pre, *mid, *post;
            pre = head;
            mid = head->next;
            post= head->next->next;
            pre->next = NULL;
            while(post->next != NULL){
                mid->next = pre;
                pre = mid;
                mid = post;
                post = post->next;
            }
            mid->next = pre;
            post->next = mid;
            return post;
        }
    }
};


//===============================
int main(){
    return 0;
}