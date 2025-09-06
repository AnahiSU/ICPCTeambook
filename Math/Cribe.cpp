#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

vector<bool> sieve(int n) {
   vector<bool> is_prime(n + 1, true);
   is_prime[0] = is_prime[1] = false;

   for (int i = 2; i <= n; i++) {
      if (!is_prime[i]) continue;
      for (int u = 2 * i; u <= n; u += i) {
         is_prime[u] = false;
      }
   }
   
   return is_prime;
}
