#include<vector>
#include<unordered_map>
#include<deque>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        deque<vector<int>> next;
        int steps = 0;
        //First, find all the rotten oranges

        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[j][i] == 2) {
                    next.push_back({i, j});
                }
            }
        }
        while (!next.empty()) {
            steps++;
            deque<vector<int>> current_layer = next;
            next.clear();
            while (!current_layer.empty()) {
                vector<int> current = current_layer.front();
                current_layer.pop_front();

                int row = current[1];
                int column = current[0];

                if (column > 0 and grid[column - 1][row] == 1) { // check up
                    grid[column -1][row] = 2;
                    next.push_back({column - 1, row});
                }

                if (row < grid[0].size() - 1 and grid[column][row + 1] == 1) { // check right
                    grid[column][row + 1] = 2;
                    next.push_back({column, row + 1});
                }

                if (row > 0 and grid[column][row - 1] == 1) { // check left
                    grid[column][row - 1] = 2;
                    next.push_back({column, row - 1});
                }

                if (column < grid.size() - 1 and grid[column + 1][row] == 1) { // check down
                    grid[column + 1][row] = 2;
                    next.push_back({column + 1, row});
                }
            }
        }

        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[j][i] == 1) {
                    return -1;
                }
            }
        }

        if (steps > 0) {return  steps - 1;}
        return steps;
    }
};


int main() {

    Solution sol;

    //vector<vector<int>> temp = {{2,1,1},{1,1,0},{0,1,1}};
    vector<vector<int>> temp = {{2,1}};
    int temp2 = sol.orangesRotting(temp);
    temp2 = sol.orangesRotting(temp);

}