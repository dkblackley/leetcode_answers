#include <iostream>
#include <tr1/unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> canConstruct(std::vector<int>& nums, int target) {

        while (!nums.empty()) {
            int number = nums.back();
            nums.pop_back();

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] + number == target) {
                    std::vector<int> vect{ i, static_cast<int>(nums.size()) };
                    return vect;
                }
            }
        }
        std::vector<int> vect;
        return vect;
    }
};

int main() {

    Solution *sol = new Solution();


    std::vector<int> vect{ 2,7,11,15 };
    sol->canConstruct(vect, 9);
    std::vector<int> vect2{ 3, 2, 4 };
    sol->canConstruct(vect2, 6);
    std::vector<int> vect3{ 3, 3 };
    sol->canConstruct(vect3, 6);
}
