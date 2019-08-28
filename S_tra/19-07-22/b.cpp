#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct Car {
  double l, s, v, i;
  bool operator<(const Car& ot) const { return s < ot.s; }
};

signed main() {
  int n;
  while (~scanf("%d", &n)) {
    n++;
    vector<Car> Vp(n);

    for (int i = n - 1; i >= 0; i--) {
      double t;
      scanf("%lf", &t);
      Vp[i].l = t;
    }
    for (int i = n - 1; i >= 0; i--) {
      double t;
      scanf("%lf", &t);
      Vp[i].s = t;
    }
    for (int i = n - 1; i >= 0; i--) {
      double t;
      scanf("%lf", &t);
      Vp[i].v = t;
    }

    // sort(Vp.begin(), Vp.end());

    Vp[n - 1].l = 0;
    double ql = Vp[0].l, qs = Vp[0].s, qv = Vp[0].v;

    // cout << ql << " " << qs << " " << qv << endl;
    for (int i = 1; i < n; i++) {
      double nl = Vp[i].l, ns = Vp[i].s, nv = Vp[i].v;
      //   double tq = (qs + ql) / qv;
      //   double tn = (ns) / nv;
      //   if (tq > tn) {
      //     ql = ql + nl;
      //     qs = qs;
      //     qv = qv;
      //   } else {
      //     ql = nl;
      //     qs = ns;
      //     qv = nv;
      //   }

      if (nv > qv) {
        double t = (double)(ns - qs - ql) / (double)(nv - qv);
        if (nv * t >= ns + nl) {
          ql = nl;
          qs = ns;
          qv = nv;
        } else {
          ql = ql + nl;
          qs = qs;
          qv = qv;
        }
      } else {
        ql = nl;
        qs = ns;
        qv = nv;
      }
        cout << qs+ql<< " " << qv << endl;

      //   cout << ql << " " << qs << " " << qv << endl;
    }
    double ss = qs + ql;
    double vv = qv;
    printf("%.10lf\n", (double)ss / (double)vv);
    // cout << (double)ss / (double)vv << endl;
  }

  return 0;
}
