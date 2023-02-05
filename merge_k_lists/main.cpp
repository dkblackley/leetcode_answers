
#include <stdio.h>
#include <vector>
#include <queue>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    /**
     * build a new list by comparing every node and adding it, use a priority queu to work out the
     * next best node to add on.
     * @param lists
     * @return
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* current = new ListNode;
        ListNode* head = current; // Make a new listnode and build the biggest
        int lowest = 0;
        priority_queue<ListNode*, vector<ListNode*>, compare_list> my_q;

        for (ListNode* list : lists) {
            if (list != nullptr) {
                my_q.push(list);
            }
        }

        while (my_q.size() > 1) {
            ListNode* smallest = my_q.top();
            my_q.pop();
            current->val = smallest->val;

            current->next = new ListNode;
            current = current->next;

            if (smallest->next != nullptr) {
                my_q.push(smallest->next);
            }
        }

        if (!my_q.empty()) {
            *current = *my_q.top();
        } else {
            return nullptr;
        }

        return head;
    }

    struct compare_list {
        bool operator()(ListNode* const & p1, ListNode* const & p2) {
            // return "true" if "p1" is ordered before "p2", for example:
            return p1->val > p2->val;
        }
    };


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return  list1;
        }

        if (list1->val >= list2->val) {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        } else {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
    }
};

int main() {

    ListNode *temp = new ListNode(4, nullptr);
    ListNode *temp2 = new ListNode(3, temp);
    ListNode *temp3 = new ListNode(2, temp2);
    ListNode *temp4 = new ListNode(1, temp3);

    ListNode *temp5 = new ListNode(8, nullptr);
    ListNode *temp6 = new ListNode(4, temp5);

    ListNode *temp7 = new ListNode(2, nullptr);
    ListNode *temp8 = new ListNode(1, temp7);

    //vector<ListNode*> vect = {temp4, temp6, temp8};
    vector<ListNode*> vect = {nullptr};
    Solution sol;
    auto test = sol.mergeKLists(vect);
    test = sol.mergeKLists(vect);

}
