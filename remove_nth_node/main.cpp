#include <iostream>

 struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * current = head;
        ListNode * lag;
        for (int i = 0; i < n - 1; ++i) {
            current = current->next;
        }
        if (current->next == nullptr) { // we're at the end of the list, pop the head!
            head = head->next;
            return head;
        }

        current = current->next;
        lag = head;

        while (current->next != nullptr) {
            current = current->next;
            lag = lag->next;
        }
        lag->next = lag->next->next;

        return head;
    }
};

int main() {

    ListNode *head = new ListNode(1);
    //head->val = 1;
    ListNode *temp = new ListNode(2);
    ListNode *temp2 = new ListNode(3);
    ListNode *temp3 = new ListNode(4);
    ListNode *temp4 = new ListNode(5);
    ListNode *temp5 = new ListNode(6);
//    temp->val = 2;
//    temp2->val = 3;
//    temp3->val = 4;
//    temp4->val = 5;
    temp->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    //temp4->val = 2;
    head->next = temp;

    Solution sol;

    auto test = sol.removeNthFromEnd(head, 1);
    test = sol.removeNthFromEnd(head, 2);

}
