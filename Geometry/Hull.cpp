vector<point> hull_andrew(vector<point>& pts) {
  int n = pts.size(), k = 0;
  vector<point> H(2 * n);
  sort(pts.begin(), pts.end());
  for (int i = 0; i < n; i++) {
    while ((k >= 2) && !ccw(H[k - 2], H[k - 1], pts[i])) k--;
    H[k++] = pts[i];
  }
  for (int i = n - 2, t = k + 1; i >= 0; i--) {
    while ((k >= t) && !ccw(H[k - 2], H[k - 1], pts[i])) k--;
    H[k++] = pts[i];
  }
  H.resize(k - 1);
  return H;
}
