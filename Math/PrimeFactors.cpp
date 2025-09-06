#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

vector<int> prime_factors(int n) {
   vector<int> v;
   while (n % 2 == 0) {
      v.push_back(2);
      n /= 2;
   }
   
   int sroot = sqrt(n);
   
   for (int i = 3; i <= sroot; i += 2) {
      while (n % i == 0) {
         v.push_back(i);
         n /= i;
      }
   }
   
   if (n > 2) {
      v.push_back(n);
   }
   
   return v;
}

