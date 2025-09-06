
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

int inv(int a) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
}

//precalculando:
inv[1] = 1;
for(int a = 2; a < m; ++a){
    inv[a] = m - (long long)(m/a) * inv[m%a] % m;
}

//version ekisd
int invMod(int a, int mod) {
    int res = 1, exp = mod - 2;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        exp /= 2;
    }
    return res;
}
