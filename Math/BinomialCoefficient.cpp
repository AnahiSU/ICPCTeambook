#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

int binomial_coeff(int n, int k) {
   int res = 1;

   // Since C(n, k) = C(n, n-k)
   if (k > n - k) {
      k = n - k;
   }

   // Calculate value of
   // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
   for (int i = 0; i < k; ++i) {
      res *= (n - i);
      res /= (i + 1);
   }

   return res;
}

//other version

const int ta = 1010;
ll bino[ta][ta];
void init()
{
    for(int i = 0; i < ta; i++) 
        bino[i][0] = 1;
    for(int i = 1; i < ta; i++) 
        for(int j = 1; j < ta; j++) 
            bino[i][j] = (bino[i - 1][j] 
                        + bino[i - 1][j-1]) % MOD;
}
