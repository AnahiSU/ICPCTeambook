#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
//optimizado para numeros grandes
int binpow(int a, int b, int n) {
    int res = 1;
    a = a % n; 
    while (b > 0) {
        if (b & 1)
            res = (res * a) % n;  
        
        a = (a * a) % n;
        b >>= 1;
    }
    return res;
}

