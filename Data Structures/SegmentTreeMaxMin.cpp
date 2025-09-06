#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const double EPS = 1e-9;

struct segtreeMaxMin{ 
    //el maximo es el first y el minimo es el second
    int n;
    vector<pair<ll,ll>> tree;

    void init(int nn) {
        tree.clear();
        n = nn;
        int size = 1;
        while (size < n) {
            size *= 2;
        }
        tree.resize(size * 2);
    }

    void update(int i, int sl, int sr, int pos, ll diff) {
        if (sl <= pos && pos <= sr) {
            if (sl == sr) {
                tree[i] = {tree[i].first+diff,tree[i].second+diff};
            } else {
                int mid = (sl + sr) / 2;
                update(i * 2 + 1, sl, mid, pos, diff);
                update(i * 2 + 2, mid + 1, sr, pos, diff);
                tree[i] = {max(tree[i * 2 + 1].first, tree[i * 2 + 2].first),min(tree[i * 2 + 1].second, tree[i * 2 + 2].second)};
            }
        }
    }

    void update(int pos, ll diff) {
        update(0, 0, n - 1, pos, diff);
    }

    pair<ll,ll> query(int i, int sl, int sr, int l, int r) {
        if (l <= sl && sr <= r) {
            return tree[i];
        } else if(sr < l || r < sl) {
            return{INT64_MIN,INT64_MAX};
        } else {
            int mid = (sl + sr) / 2;
            auto a = query(i * 2 + 1, sl, mid, l, r);
            auto b = query(i * 2 + 2, mid + 1, sr, l, r);
            return {max(a.first,b.first),min(a.second,b.second)};
        }
    }

    pair<ll,ll> query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};    
