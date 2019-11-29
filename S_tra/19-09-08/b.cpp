#include <cmath>
#include <iostream>
using namespace std;
struct Line {
  double x1;
  double y1;
  double x2;
  double y2;
};

bool intersection(const double& x1, const double& y1, const double& x2,
                  const double& y2, const double& x3, const double& y3,
                  const double& x4, const double& y4) {
  if ((x1 > x2 ? x1 : x2) < (x3 < x4 ? x3 : x4) ||
      (y1 > y2 ? y1 : y2) < (y3 < y4 ? y3 : y4) ||
      (x3 > x4 ? x3 : x4) < (x1 < x2 ? x1 : x2) ||
      (y3 > y4 ? y3 : y4) < (y1 < y2 ? y1 : y2)) {
    return false;
  }
  if ((((x1 - x3) * (y4 - y3) - (y1 - y3) * (x4 - x3)) *
       ((x2 - x3) * (y4 - y3) - (y2 - y3) * (x4 - x3))) > 0 ||
      (((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)) *
       ((x4 - x1) * (y2 - y1) - (y4 - y1) * (x2 - x1))) > 0) {
    return false;
  }
  return true;
}
void jiao(const double& x1, const double& y1, const double& x2,
          const double& y2, const double& x3, const double& y3,
          const double& x4, const double& y4, double& x, double& y) {
  x = ((x1 - x2) * (x3 * y4 - x4 * y3) - (x3 - x4) * (x1 * y2 - x2 * y1)) /
      ((x3 - x4) * (y1 - y2) - (x1 - x2) * (y3 - y4));
  y = ((y1 - y2) * (x3 * y4 - x4 * y3) - (x1 * y2 - x2 * y1) * (y3 - y4)) /
      ((y1 - y2) * (x3 - x4) - (x1 - x2) * (y3 - y4));
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

    if (y1 < y2) {  // 保证 1 在 2 上
      double tx = x1;
      double ty = y1;
      x1 = x2;
      y1 = y2;
      x2 = tx;
      y2 = ty;
    }
    if (y3 < y4) {  // 保证 3 在 4 上
      double tx = x3;
      double ty = y3;
      x3 = x4;
      y3 = y4;
      x4 = tx;
      y4 = ty;
    }
    if (intersection(x1, y1, x2, y2, x3, y3, x4, y4)) {
      double ans = 0;
      double jx, jy;
      jiao(x1, y1, x2, y2, x3, y3, x4, y4, jx, jy);
      if (y1 > y3) {
        if (intersection(x1, y1, x2, y2, x3, y3, x3 - 1, y3)) {
          double spjx, spjy;
          jiao(x1, y1, x2, y2, x3, y3, x3 - 1, y3, spjx, spjy);
          double h = abs(y3 - jy);
          double k = abs(spjx - x3);
          ans += (h * k) / 2.0;
        }
      } else {
        if (intersection(x1, y1, x1 - 1, y1, x3, y3, x4, y4)) {
          double spjx, spjy;
          jiao(x1, y1, x1 - 1, y1, x3, y3, x4, y4, spjx, spjy);
          double h = abs(y1 - jy);
          double k = abs(spjx - x1);
          ans += (h * k) / 2.0;
        }
      }

      if (y2 > y4) {
        if (intersection(x1, y1, x2, y2, x4, y4, x4 - 1, y4)) {
          double spjx, spjy;
          jiao(x1, y1, x2, y2, x3, y3, x3 - 1, y3, spjx, spjy);
          double h = abs(y3 - jy);
          double k = abs(spjx - x3);
          ans += (h * k) / 2.0;
        }
      } else {
        if (intersection(x1, y1, x1 - 1, y1, x3, y3, x4, y4)) {
          double spjx, spjy;
          jiao(x1, y1, x1 - 1, y1, x3, y3, x4, y4, spjx, spjy);
          double h = abs(y1 - jy);
          double k = abs(spjx - x1);
          ans += (h * k) / 2.0;
        }
      }

      printf("%.2lf", ans);
    } else {
      printf("%.2lf", 0.0);
    }
    putchar('\n');
  }

  return 0;
}