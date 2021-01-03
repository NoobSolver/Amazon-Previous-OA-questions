#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 7;
vector<int> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];


void IS_CUTPOINT(int v) {
    cout << v << ", ";
}

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        IS_CUTPOINT(v);
}

int main() {

    // Input: numNodes = 7, numEdges = 7, edges = [[0, 1], [0, 2], [1, 3], [2, 3], [2, 5], [5, 6], [3, 4]]
    // Output: [2, 3, 5]

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 5}, {5, 6}, {3, 4}};

    int n = MAXN;
    timer = 0;

    // fill g

    for(auto e: edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }

/*
    cout << "Graph: " << endl;
    for(int i = 0; i < MAXN; ++i) {
        cout << "Node: " << i << ": ";
        for(auto n: g[i]) {
            cout << n << ", ";
        }
        cout << endl;
    }
    cout << endl;
*/

    cout << "Articulation points: " << endl;

    for (int i=0; i<n; ++i)
        used[i] = false;
    dfs (0);

    return 0;
}

