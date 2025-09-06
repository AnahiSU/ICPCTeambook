#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

vector<int> findDivisors(int n) {
   vector<int> v;
   for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
         v.push_back(i);
         int other = n / i;
         if (other != i) { // case i * i = n
            v.push_back(other);
         }
      }
   }
   return v;
}

long long SumOfDivisors(long long num) {
    long long total = 1;

    for (int i = 2; (long long)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);

            long long sum = 0, pow = 1;
            do {
                sum += pow;
                pow *= i;
            } while (e-- > 0);
            total *= sum;
        }
    }
    if (num > 1) {
        total *= (1 + num);
    }
    return total;
}
