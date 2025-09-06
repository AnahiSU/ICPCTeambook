#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

//O(log(y))
int power(int x, int y, int MOD) { 
    int res = 1;     
    x = x % MOD;  
    if (x == 0) return 0; 
    while (y > 0){  
        if (y & 1) 
            res = (res*x) % MOD; 

        y = y>>1;  
        x = (x*x) % MOD; 
    } 
    return res; 
}
