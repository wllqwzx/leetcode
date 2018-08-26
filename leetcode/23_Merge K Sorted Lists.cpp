#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct my_prior
{
    bool operator()(ListNode *a, ListNode *b) const
    {
        return a->val > b->val;
    }
};

class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, my_prior> q;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
                q.push(lists[i]);
        }

        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        while (!q.empty())
        {
            if (tail != nullptr)
            {
                tail->next = q.top();
                tail = tail->next;
            }
            else
                tail = q.top();
            q.pop();
            if (head == nullptr)
                head = tail;
            if (tail->next != nullptr)
                q.push(tail->next);
        }
        return head;
    }
};