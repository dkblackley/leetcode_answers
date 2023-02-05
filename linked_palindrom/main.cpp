#include <iostream>
#include <vector>

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

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> numbers;
        numbers.push_back(head->val);
        ListNode* next = head->next;

        while (next != nullptr) {
            numbers.push_back(next->val);
            next = next->next;
        }

//        if (numbers.size() % 2 == 1) {
//            if (numbers.size() == 1) {
//                return true;
//            }
//            numbers.erase(numbers.begin() + (int) numbers.size()/2);
//        }

//        std::cout << (numbers.size()) << std::endl;

        std::vector<int> first_half(numbers.begin(), numbers.begin() + ((float) numbers.size()/2 + 0.5));
        std::vector<int> second_half(numbers.rbegin(), numbers.rend()  - numbers.size()/2);

        if (first_half == second_half) {
            return true;
        }

        return false;
    }
};

int main() {

    ListNode* end = new ListNode(1);
    ListNode* prev_node = end;
//    ListNode* new_node = new ListNode(2, prev_node);
//    prev_node = new_node;
//    new_node = new ListNode(2, prev_node);
//    prev_node = new_node;
//    new_node = new ListNode(1, prev_node);
//
//    for (int i = 0; i < 10; ++i) {
//        prev_node = new_node;
//        new_node = new ListNode(i, prev_node);
//    }

//    ListNode * head = new_node;
    ListNode * head = prev_node;
    std::cout << head << std::endl;

    Solution* sol = new Solution();

    bool temp = sol->isPalindrome(head);

    sol->isPalindrome(head);
}