struct SegmentTree {
  int n;
  vector<long long> t, lazy;

  SegmentTree(int n) : n(n) {
    t.assign(4*n, 0); lazy.assign(4*n, 0); }

  void build(vector<int>& a) {
    build(a, 1, 0, n-1);
  }

  void update(int l, int r, int add) {
    update(1, 0, n-1, l, r, add);
  }

  long long query(int l, int r) {
    return query(1, 0, n-1, l, r);
  }

  private:
  void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = a[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(a, v*2, tl, tm);
      build(a, v*2+1, tm+1, tr);
      t[v] = t[v*2] + t[v*2+1];
    }
  }

  void push(int v, int tl, int tr) {
    if (lazy[v] != 0) {
      int tm = (tl + tr) / 2;
      t[v*2] += lazy[v] * (tm - tl + 1);
      lazy[v*2] += lazy[v];
      t[v*2+1] += lazy[v] * (tr - tm);
      lazy[v*2+1] += lazy[v];
      lazy[v] = 0;
    }
  }

  void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r) return;
    if (l == tl && r == tr) {
      t[v] += 1LL * add * (tr - tl + 1);
      lazy[v] += add;
    } else {
      push(v, tl, tr);
      int tm = (tl + tr) / 2;
      update(v*2, tl, tm, l, min(r, tm), add);
      update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
      t[v] = t[v*2] + t[v*2+1];
    }
  }

  long long query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l <= tl && tr <= r) {
      return t[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm)) +
      query(v*2+1, tm+1, tr, max(l, tm+1), r);
  }
};
