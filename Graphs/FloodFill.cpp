#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

struct FloodFill {
    vector<vector<int>> tab;
    vector<vector<int>> visi;
    int n, m;
    
    void init(vector<vector<int>> &tablero) {
        tab = tablero;
        n = tab.size();
        m = tab[0].size();
        visi.assign(n, vector<int>(m, 0));
    }

    int floodfill(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m || visi[x][y] || tab[x][y] == 0)
            return 0;
        visi[x][y] = 1;
        int ret = 1;
        //int dir[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
        int dir[2][8] = {{0, 0, 1, -1, 1, 1, -1, -1}, {1, -1, 0, 0, 1, -1, 1, -1}};
        for (int i = 0; i < 8; i++)
            ret += floodfill(x + dir[0][i], y + dir[1][i]);
        return ret;
    }
};
