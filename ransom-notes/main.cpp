#include <iostream>
#include <tr1/unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {

        std::tr1::unordered_map<char, int> char_map;

        for (char character : ransomNote) {
            char_map[character]++;
        }

        std::tr1::unordered_map<char, int> mag_map;

        for (char character : magazine) {
            mag_map[character]++;
        }

        for (auto kv: char_map) {
            char key = kv.first;

            if (char_map[key] > mag_map[key]) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    Solution *sol = new Solution();
    sol->canConstruct("a", "b");
    sol->canConstruct("aa", "aab");
    sol->canConstruct("b", "ab");

}
