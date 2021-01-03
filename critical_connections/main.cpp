#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 5;
vector<int> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];


void IS_BRIDGE(int v, int to) {
    cout << v << ", " << to << endl;
}


void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v])
                IS_BRIDGE(v+1,to+1);
        }
    }
}

int main() {

/*
    Input: n = 5, edges = [[1, 2], [1, 3], [3, 4], [1, 4], [4, 5]]
    Output: [[1, 2], [4, 5]]
*/

    vector<vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}, {1, 4}, {4, 5}};

    int n = MAXN;
    timer = 0;

    // fill g

    for(auto e: edges) {
        g[e[0]-1].push_back(e[1]-1);
        g[e[1]-1].push_back(e[0]-1);
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

    cout << "Bridges: " << endl;

    for (int i=0; i<n; ++i)
        used[i] = false;
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);

    return 0;
}

