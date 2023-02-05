#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char, char> my_map;

        my_map[')'] = '(';
        my_map['}'] = '{';
        my_map[']'] = '[';
        my_map['['] = 1;
        my_map['{'] = 1;
        my_map['('] = 1;


        for (char letter : s) {
            if (my_map[letter] == 1) {
                stack.push_back(letter);
            } else {
                if (stack.empty() || stack.back() != my_map[letter]) {
                    return false;
                }
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};

int main() {
    Solution sol;

    auto test = sol.isValid("[");
    test = sol.isValid("");
    test = sol.isValid("[[}]");
    test = sol.isValid("[[]]");
}
