#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

void bfs(int v, const vector<vector<int>>& g, vector<bool>& visi) {
    deque<int> cola;
    cola.push_back(v);
    visi[v] = true;
    while (!cola.empty()) {
        int v = cola.front();
        cola.pop_front();
        for (int vec : g[v]) {
            if (!visi[vec]) {
                cola.push_back(vec);
                visi[vec] = true;
            }
        }
    }
}
