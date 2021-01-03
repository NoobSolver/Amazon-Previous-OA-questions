#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// question source:
// https://leetcode.com/discuss/interview-question/411357/


struct node_t { int row = 0, col = 0; };

int min_hours(vector<vector<int>> &matrix) {
    int hours = -1; // return -1 in case of error

    int directions[4][2] = {{1,  0}, {-1, 0}, {0,  1}, {0,  -1}};

    size_t rows = matrix.size();
    size_t cols = rows ? matrix[0].size() : 0; // to prevent access error when rows == 0

    // collect all positions of the zombies into a queue
    queue<node_t> q;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) { q.push({i, j}); }
        }
    }
    // Do BFS until the end of the humans
    while (!q.empty()) {
        int q_size = q.size();
        // Process all positions which are already added into the queue.
        for (int i = 0; i < q_size; i++) {
            auto node = q.front();
            q.pop();
            // Find all humans in adjacent cells and add them into the queue
            for (auto dir: directions) {
                int nr = node.row + dir[0];
                int nc = node.col + dir[1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] == 0) {
                    q.push({nr, nc});
                    matrix[nr][nc] = 1;
                }
            }
        }
        hours++;
    }
    return hours;
}


int main() {

    vector<vector<int>> empty = {};
    vector<vector<int>> one = {{0,0}};
    vector<vector<int>> two = {{0,0},{0,1}};

    vector<vector<int>> m0 = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
    };

    vector<vector<int>> m1 = {
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
    };

    vector<vector<int>> m = {
            {0, 1, 1, 0, 1},
            {0, 1, 0, 1, 0},
            {0, 0, 0, 0, 1},
            {0, 1, 0, 0, 0},
    };


    cout << min_hours(m) << endl;

    return 0;
}