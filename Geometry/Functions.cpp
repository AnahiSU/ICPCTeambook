vec to_vec(const point& a, const point& b) {
  return vec(b.x - a.x, b.y - a.y);
}
ll dot(const vec& u, const vec& v) {
  return (u.x * v.x + u.y * v.y);
}
ll cross(const vec& u, const vec& v) {
  return (u.x * v.y - u.y * v.x);
}
// > 0 -> left turn ; = 0 -> collinear ; < 0 -> right turn
ll orient(const point& p, const point& q, const point& r) {
  return cross(to_vec(p, q), to_vec(p, r));
}
// return true if point p lies on the disk with diameter ab
bool in_disk(const point& a, const point& b, const point& p) {
  return dot(to_vec(p, a), to_vec(p, b)) <= 0;
}
// return true if point p is on segment ab, false otherwise
bool on_segment(const point& a, const point& b, const point &p) {
  return orient(a, b, p) == 0 && in_disk(a, b, p);
}
bool above(const point& a, const point& b) {
  return a.y >= b.y;
}
bool crosses_ray(const point& p, const point& q, const point& a) {
  return (above(q, a) - above(p, a)) * orient(a, p, q) > 0;
}
bool ccw(const point& p, const point& q, const point& r) {
  return orient(p, q, r) >= 0;
}
// return 1 if is insise, -1 if is outside and 0 if is on the perimeter
int in_polygon(const point& a, vector<point>& pol) {
  int num_crossings = 0;
  int n = pol.size();
  point p, q;
  for (int i = 0; i < n; i++) {
    p = pol[i];
    q = pol[(i + 1) % n];
    if (on_segment(p, q, a)) {
      return 0;
    }
    num_crossings += crosses_ray(p, q, a);
  }
  return ((num_crossings & 1) ? 1 : -1);
}
