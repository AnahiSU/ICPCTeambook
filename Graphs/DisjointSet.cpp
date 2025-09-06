#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const double EPS = 1e-9;

struct ConjuntoDisjunto {
    vector<int> padre;
    vector<int> rango;

    ConjuntoDisjunto(int n) {
        padre.resize(n + 1);
        rango.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            padre[i] = i;
        }
    }

    int encontrar(int v) {
        if (padre[v] != v) {
            padre[v] = encontrar(padre[v]);
        }
        return padre[v];
    }

    void unir(int u, int v) {
        int raizU = encontrar(u);
        int raizV = encontrar(v);

        if (raizU != raizV) {
            if (rango[raizU] < rango[raizV]) {
                padre[raizU] = raizV;
            } else if (rango[raizU] > rango[raizV]) {
                padre[raizV] = raizU;
            } else {
                padre[raizV] = raizU;
                rango[raizU]++;
            }
        }
    }
};
