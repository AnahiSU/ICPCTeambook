#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

void dfs(int v, const vector<vector<int>>&g, vector<bool>& visi) {
    if (!g[v]) {
        visi[v] = true;
        for (int vec : g[v]) {
            dfs(vec, g, visi);
        }
    }
}
