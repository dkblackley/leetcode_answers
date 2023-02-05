#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using namespace tr1;

class Solution {
    /**
     * DP solution, we need to remember what the previous palindrome was so we don't have to keep re-calculating
     */
public:
    int maxArea(vector<int>& height) {
        int first_node = 0;
        int last_node = height.size() - 1;
        int max_area = 0;

        while (&height[first_node]  != &height[last_node]) {
            int smallest = min(height[first_node], height[last_node]);
            int area = (last_node - first_node) * smallest;
            max_area = max(area, max_area);

            if (height[first_node] > height[last_node]) {
                last_node--;
            } else {
                first_node++;
            }
        }

        return max_area;
    }
};

int main() {

    Solution *sol = new Solution();
    vector<int> temparr = vector<int> {1,8,6,2,5,4,8,3,7};
    auto temp = sol->maxArea(temparr);
    temparr.clear();
    temparr = vector<int> {1,8,6,2,5,4,8,3,7};
    temp = sol->maxArea(temparr);

}