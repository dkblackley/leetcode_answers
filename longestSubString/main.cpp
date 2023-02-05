#include <iostream>
#include <tr1/unordered_map>
#include <vector>

using namespace std;
using namespace tr1;

class Solution {
public:
    /**
     * Sliding window algorithim using a hashmap. First we slide the right window along untila  repeat is found, then we
     * jump the left window to the next character after the repeated character
     * @param s
     * @return
     */
    int lengthOfLongestSubstring(std::string s) {

        unordered_map<char, int> m;

        int l = 0; //left window index
        int r = 0; //right window index
        int biggest = 0;

        while (r < s.length()) {
            if (m[s[r]] > 0) { // if a repeat is found
                l = std::max(m[s[r]], l); //don't let the left window slide back if we find a repeat too early.
            }
            m[s[r]] = r + 1;
            biggest = std::max(biggest, r - l + 1);
            r++;
        }

        return biggest;
    }
};

int main() {

    Solution *sol = new Solution();

    sol->lengthOfLongestSubstring("yfsrsrpzuya");
    sol->lengthOfLongestSubstring("aaba");
    sol->lengthOfLongestSubstring("abcabcbb");
    sol->lengthOfLongestSubstring("bbbbb");
    sol->lengthOfLongestSubstring("acbacbeda");
}
