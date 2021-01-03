#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

using cells_t = bitset<8>;

// --------------- Leetcode ---------------------

//    these convertion functions need only because
//    of input type is vector<int> which I can't change to pass the auto test on leetcode.com
//    But I'd prefer bitset<8> type everywhere because it is better describes the task
//    and because unordered_map doesn't work with vector<int> as a key directly

cells_t vector_to_bitset(const std::vector<int> & cells) {
    cells_t bits;
    for (auto i = 0; i < 8; ++i) {
        bits[i] = cells[i];
    }
    return bits;
}

std::vector<int> bitset_to_vector(const cells_t & bits) {
    vector<int> cells(8);
    for (auto i = 0; i < 8; ++i) {
        cells[i] = bits[i];
    }
    return cells;
}

vector<int> prisonAfterNDays_Leetcode(vector<int>& cells_vector, int N) {
    // because unordered_map has constant access complexity. O(1)
    unordered_map<cells_t, int> seen;

    cells_t cells = vector_to_bitset(cells_vector);

    while (N > 0) {
        cells_t cells2;

        seen[cells] = N--;

        for (int i = 1; i < 7; ++i) {
            cells2[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
        }

        cells = cells2;

        cout << "N = " << N << endl;
        cout << cells << endl;
        auto pair = seen.find(cells);

        if ( pair != seen.end()) {
            auto diff = pair->second - N;
            if(diff > 0) {
                N %= diff;
            }
        }

    }
    return bitset_to_vector(cells);
}


// ------ Amazon ---------

cells_t array_to_bitset(int* states) {
    cells_t bits;
    for (auto i = 0; i < 8; ++i) {
        bits[i] = states[7-i];
    }
    return bits;
}


std::vector<int> bitset_to_vector_Amazon(const cells_t & bits) {
    vector<int> cells(8);
    for (auto i = 0; i < 8; ++i) {
        cells[i] = bits[7-i];
    }
    return cells;
}

vector<int> prisonAfterNDays_Amazon(int* states, int N) {
    // because unordered_map has constant access complexity. O(1)
    unordered_map<cells_t, int> seen;

    cells_t cells = array_to_bitset(states);

    while (N > 0) {
        cells_t cells2;

        seen[cells] = N--;

        // first bit
        cells2[0] = 0 != cells[1];

        for (int i = 1; i < 7; ++i) {
            cells2[i] = cells[i - 1] != cells[i + 1];
        }

        // last bit
        cells2[7] = 0 != cells[6];

        cells = cells2;

        auto pair = seen.find(cells);

        if ( pair != seen.end()) {
            auto diff = pair->second - N;
            if(diff > 0) {
                N %= diff;
            }
        }
    }
    return bitset_to_vector_Amazon(cells);
}


vector<int> cellCompete(int* states, int days) {
    return prisonAfterNDays_Amazon(states, days);
}

// ------

// -------- Bonus solution for the second test task -------

static int gcd(int x, int y) {
    int r;

    if (x <= 0 || y <= 0) { return 0; }

    while ((r = x % y) != 0) {
        x = y;
        y = r;
    }

    return y;
}

int generalizedGCD(int num, int* arr) {
    int g = arr[0];

    for (int i = 1; i < num; i++) {
        g = gcd(g, arr[i]);
    }

    return g;

}

// ------------


int main() {

    // vector<int> cells = {1,0,0,0,0,1,0,0}; 1
    // "Expected: [0,1,0,0,1,0,1,0]"

    // vector<int> cells = {1,1,1,0,1,1,1,1}; 2
    // "Expected: [0,0,0,0,0,1,1,0]"

    vector<int> cells = {1,1,1,0,1,1,1,1};
    vector<int> res = prisonAfterNDays_Amazon(cells.data(), 2);

    cout << "Amazon Input: cells = [1,1,1,0,1,1,1,1], N = 2" << endl <<
         "Expected: [0,0,0,0,0,1,1,0]" << endl <<
         "Actual output: ";

    for (auto i : res) {
        cout << i << " ";
    }

    cout << endl << endl;

    vector<int> cells2 = {0,1,0,1,1,0,0,1};

    res = prisonAfterNDays_Leetcode(cells2, 7);

    cout << "Leetcode Input: cells2 = [0,1,0,1,1,0,0,1], N = 7" << endl <<
         "Expected: [0,0,1,1,0,0,0,0]" << endl <<
         "Actual output: ";

    for (auto i : res) {
        cout << i << " ";
    }

    return 0;
}