//#include <unordered_map>
#include <iostream>
#include <cassert>
#include <tr1/unordered_map>
#include <string>

using std::string;

class Solution {
public:
    int romanToInt( string s) {

        std::tr1::unordered_map<char, int> m;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        std::cout << s << "\n";

        int result = 0;

        for ( std::string::size_type i = 0; i < s.size(); i++) {

            if (s[i] == 'I') {
                if (s[i + 1] == 'V') {
                    result += 4;
                    i++;
                } else if (s[i + 1] == 'X') {
                    result += 9;
                    i++;
                } else {
                    result++;
                    while (&s[i] != &s.back()) {
                        result++;
                        i++;
                    }
                }
            } else if (s[i] == 'X') {
                if (s[i + 1] == 'L') {
                    result += 40;
                    i++;
                } else if (s[i + 1] == 'C') {
                    result += 90;
                    i++;
                } else {
                    result += m[s[i]];
                }

            } else if (s[i] == 'C') {
                if (s[i + 1] == 'D') {
                    result += 400;
                    i++;
                } else if (s[i + 1] == 'M') {
                    result += 900;
                    i++;
                } else {
                    result += m[s[i]];
                }

            } else {
                result += m[s[i]];
            }
         }
        return result;
    }
};

int main() {
    Solution rit = *new Solution();
    int i = rit.romanToInt("DCXXI");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
