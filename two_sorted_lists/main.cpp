
#include <stdio.h>

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
    ListNode *temp7 = new ListNode(2, temp6);
    ListNode *temp8 = new ListNode(1, temp7);



    Solution sol;
    auto test = sol.mergeTwoLists(nullptr, nullptr);
    test = sol.mergeTwoLists(temp4, temp8);

}
