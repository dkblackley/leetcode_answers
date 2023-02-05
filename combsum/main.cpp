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

    vector<vector<int>> *answers;
    vector<int> *c;
    int t;

    void backtrack(vector<int> this_sum, int total, int internal_index) {

        if (total > t) { return; } // we went too far, jump away from this
        else if (total == t) {
            answers->push_back(this_sum);
            return;
        } else { // else we can go further down this road
            vector<int> candidates = *c;
            for (int i = internal_index; i < candidates.size(); ++i) { // try all combinations with this combination
                this_sum.push_back(candidates[i]);
                backtrack(this_sum, total + candidates[i], i); // use internal index to keep things unique
                this_sum.pop_back();
            }
        }
    }


    /**
     * A backtracking algorithim. The usual solution when told to find "every possible". Start with the full list, if
     * it sums to grater than the target, pop off the largest element (backtrack) and then check if the sum is larger than the
     * biggest element. Once it's not, try adding the smallest element. If this is equal to or greater than the largest element,
     * stop, but if not then try adding that element again and again until it does, then go back one step and try adding the second
     * largest element. If that's too big then pop off until we get back to the original node, then try popping off again and repeat.
     * @param candidates
     * @param target
     * @return
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        t = target;
        c = &candidates;
        answers = new vector<vector<int>>();
        vector<int> current_comb;

        backtrack(current_comb, 0, 0);
        return *answers;

    }
};



int main() {

    Solution *sol;
    vector<int> temparr = vector<int>{2};
    //vector<int> temparr = vector<int>{0,1,2,4,5,6,7};
    //vector<int> temparr = vector<int>{2,4,5,6,7,0,1};
    auto temp = sol->combinationSum(temparr, 1);
    temp = sol->combinationSum(temparr, 0);
    temparr.clear();
    temparr = vector<int>{-1, 0, 1, 2, -1, -4};


}