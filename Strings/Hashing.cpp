#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

const int mod = 1e9 + 7;
const int p = 31; // para mayusculas y minusculas 53
int getHash(string s) {
  int ans = 0;
  int n = s.size();
  int base = 1;
  for (int i = 0; i < n; i++) {
    ans += (s[i]-'a'+1) * base % mod;
    ans %= ans;
    base = base * p % mod;
  }
  return ans;
}
