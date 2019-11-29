#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
int sgn(double x) {
  if (fabs(x) < eps) return 0;
  if (x < 0)
    return -1;
  else
    return 1;
}
struct Point {
  double x, y;
  Point() {}
  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  double operator^(const Point &b) const { return x * b.y - y * b.x; }
  double operator*(const Point &b) const { return x * b.x + y * b.y; }
};
struct Line {
  Point s, e;
  Line() {}
  Line(Point _s, Point _e) {
    s = _s;
    e = _e;
  }
  pair<int, Point> operator&(const Line &b) const {
    Point res = s;
    if (sgn((s - e) ^ (b.s - b.e)) == 0) {
      if (sgn((s - b.e) ^ (b.s - b.e)) == 0)
        return make_pair(0, res);
      else
        return make_pair(1, res);
    }
    double t = ((s - b.s) ^ (b.s - b.e)) / ((s - e) ^ (b.s - b.e));
    res.x += (e.x - s.x) * t;
    res.y += (e.y - s.y) * t;
    return make_pair(2, res);
  }
};

bool inter(Line l1, Line l2) {
  return max(l1.s.x, l1.e.x) >= min(l2.s.x, l2.e.x) &&
         max(l2.s.x, l2.e.x) >= min(l1.s.x, l1.e.x) &&
         max(l1.s.y, l1.e.y) >= min(l2.s.y, l2.e.y) &&
         max(l2.s.y, l2.e.y) >= min(l1.s.y, l1.e.y) &&
         sgn((l2.s - l1.e) ^ (l1.s - l1.e)) *
                 sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <=
             0 &&
         sgn((l1.s - l2.e) ^ (l2.s - l2.e)) *
                 sgn((l1.e - l2.e) ^ (l2.s - l2.e)) <=
             0;
}

double f(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  Line l1, l2;
  l1 = Line(Point(x1, y1), Point(x2, y2));
  l2 = Line(Point(x3, y3), Point(x4, y4));
  if (sgn(l1.s.y - l1.e.y) == 0 || sgn(l2.s.y - l2.e.y) == 0) {
    return 0.0;
  }
  if (sgn(l1.s.y - l1.e.y) < 0) swap(l1.s, l1.e);
  if (sgn(l2.s.y - l2.e.y) < 0) swap(l2.s, l2.e);
  if (inter(l1, l2) == false) {
    return 0.0;
  }
  if (inter(Line(l1.s, Point(l1.s.x, 1000000)), l2)) {
    return 0.0;
  }
  if (inter(Line(l2.s, Point(l2.s.x, 1000000)), l1)) {
    return 0.0;
  }
  pair<int, Point> pr;
  pr = l1 & l2;
  Point p = pr.second;
  double ans1;
  pr = l1 & Line(Point(1000000, l2.s.y), l2.s);
  Point p1 = pr.second;
  ans1 = fabs((l2.s - p) ^ (p1 - p)) / 2;
  double ans2;
  pr = l2 & Line(Point(1000000, l1.s.y), l1.s);
  Point p2 = pr.second;
  ans2 = fabs((l1.s - p) ^ (p2 - p)) / 2;
  return min(ans1, ans2);
}

int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4;
  int T;

  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    printf("%.2lf\n", f(x1, y1, x2, y2, x3, y3, x4, y4) +
                          f(x1, -y1, x2, -y2, x3, -y3, x4, -y4));
  }
  return 0;
}