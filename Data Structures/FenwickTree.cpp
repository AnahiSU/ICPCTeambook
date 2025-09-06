#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

 struct BIT { // 1-indexed, your first element of the array is at index 1
    vector<ll> bit;
    ll n;
    BIT(int n) : bit(n+1), n(n) {}

    ll lsb(int i) { return i & -i; } // least significant bit
	
	 void add(int i, ll x) {
        for (; i <= n; i += lsb(i)) bit[i] += x;
    }

    ll sum(int r) {
        ll res = 0;
        for (; r > 0; r -= lsb(r)) res += bit[r];
        return res;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    void set(int i, ll x) {
        add(i, x - sum(i, i));
    }
};
