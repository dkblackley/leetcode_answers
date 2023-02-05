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


    //find smallest element and rotate
    int search(vector<int>& nums, int target) {

        //int start = 0;
        int end = nums.size() - 1;
        int start = 0;

        while (start<end) { // while the indexes aren't the same
            int mid = (start+end)/2;
            if (nums[mid] > nums[end]) { start=mid+1; } // if the middle value is larger that the value furthest to the right, change the start to be the middle!
            else { end=mid; }
        }
        int true_beggining = start; // this is how much the array has been rotated by

        start = 0; end = nums.size() -1;

        while (start <= end) {
            int mid = (start + end) / 2;
            int rot_mid = (mid + true_beggining) % nums.size();

            if (nums[rot_mid] == target) {
                return rot_mid;
            }

            if (nums[rot_mid] < target) { //get the left half
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }
};



int main() {

    Solution *sol = new Solution();
    vector<int> temparr = vector<int>{4,5,6,7,0,1,2};
    //vector<int> temparr = vector<int>{0,1,2,4,5,6,7};
    //vector<int> temparr = vector<int>{2,4,5,6,7,0,1};
    auto temp = sol->search(temparr, 0);
    temp = sol->search(temparr, 0);
    temparr.clear();
    temparr = vector<int>{-1, 0, 1, 2, -1, -4};


}