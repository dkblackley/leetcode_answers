#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * Make your own hasmap, mapping the string "0#0#0#0#0... * 26 to the array of string that match. Can be done faster with CPP
     * string sort, but that's not as impressive lol
     * @param strs
     * @return
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> my_map;
        vector<vector<string>> answer;

        for (string s : strs) {
            my_map[make_key(s)].push_back(s);
        }

        for (auto it: my_map) {
            answer.push_back(it.second);
        }
        return answer;
    }

    string make_key(string word) {
        int count[26];
        fill(begin(count), end(count), 0);

        for (char c : word) {
            count[c - 'a']++;
        }

        string new_string = "";

        for (int i = 0; i < 26; ++i) {
            new_string += (to_string(count[i]) + "#");
        }

        return new_string;

    }

};





//Size of array is 133
int main() {

    Solution sol;

    vector<string> s = {"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};

    auto ans = sol.groupAnagrams(s);
    ans = sol.groupAnagrams(s);

}