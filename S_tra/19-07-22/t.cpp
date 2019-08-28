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
    vector<Car> Vp(n+1);

    for (int i = 0; i <= n; i++) {
      scanf("%lf", &Vp[i].l);
    }
    for (int i = 0; i <= n; i++) {
      scanf("%lf", &Vp[i].s);
    }
    for (int i = 0; i <= n; i++) {
      scanf("%lf", &Vp[i].v);
    }
    double sum = 0,ans = 1.0*Vp[0].s/Vp[0].v;
    for( int i = 1; i <= n; i++){
        sum += Vp[i].l;
        ans = max(1.0*(Vp[i].s+sum)/Vp[i].v,ans);
    }
    printf("%.10lf\n",ans);

  }

  return 0;
}
