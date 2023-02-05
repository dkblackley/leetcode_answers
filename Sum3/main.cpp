#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using namespace tr1;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> answer_map;
        vector<vector<int>> answer;
        std::tr1::unordered_map<int, int> num_map;

        for (int p = 0; p != nums.size(); p++) {
            int i = nums[p];
            if (answer_map.find(i) != answer_map.end()) { continue; } //skip this number if it's already answered

            for (int k = p + 1; k != nums.size(); k++) {
                int j = nums[k];
                if (answer_map.find(j) != answer_map.end()) { continue; } //skip this number if it's already got an answer

                if (num_map.find((i + j) * - 1) != num_map.end()) { // if there is a solution we saw previously
                    vector<int> temp_vec = {i, j, (i + j) * -1};
                    answer.push_back(temp_vec);
                    //answer_map[i] = i; // we've seen these now, continue if we see them again
                    answer_map[j] = j;
                }
            }
            num_map[i] = i;
        }
        return answer;
    }
};

int main() {

    Solution *sol = new Solution();
    vector<int> temparr = vector<int> {3, 0, -2, -1,1,2};
    auto temp = sol->threeSum(temparr);
    temparr.clear();
    temparr = vector<int> {-1,0,1,2,-1,-4};
    temp = sol->threeSum(temparr);

}