struct point {
  ll x, y;
  point() {x = y = 0L;}
  point(ll _x, ll _y) : x(_x), y(_y) {}
  bool operator < (point other) const {
    if (x == other.x) {
      return y < other.y;
    }
    return x < other.x;
  }
};

struct vec {
  ll x, y;
  vec(ll _x, ll _y) : x(_x), y(_y) {}
};
