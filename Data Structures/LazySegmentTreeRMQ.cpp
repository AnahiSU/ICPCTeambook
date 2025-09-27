struct SegmentTree {
  int n;
  vector<int> t, lazy;

  SegmentTree(int n) : n(n) {
    t.assign(4*n, 0);
    lazy.assign(4*n, 0);
  }

  void build(vector<int>& a) {
    build(a, 1, 0, n-1);
  }

  void update(int l, int r, int add) {
    update(1, 0, n-1, l, r, add);
  }

  int query(int l, int r) {
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
      t[v] = min(t[v*2], t[v*2+1]);
    }
  }

  void push(int v) {
    if (lazy[v] != 0) {
      t[v*2] += lazy[v];
      lazy[v*2] += lazy[v];
      t[v*2+1] += lazy[v];
      lazy[v*2+1] += lazy[v];
      lazy[v] = 0;
    }
  }

  void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r) return;
    if (l == tl && r == tr) {
      t[v] += add;
      lazy[v] += add;
    } else {
      push(v);
      int tm = (tl + tr) / 2;
      update(v*2, tl, tm, l, min(r, tm), add);
      update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
      t[v] = min(t[v*2], t[v*2+1]);
    }
  }

  int query(int v, int tl, int tr, int l, int r) {
    if (l > r) return INF;
    if (l <= tl && tr <= r) {
      return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    return min(
        query(v*2, tl, tm, l, min(r, tm)),
        query(v*2+1, tm+1, tr, max(l, tm+1), r)
        );
  }
};
