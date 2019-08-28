// P1081 开车旅行
// https://www.luogu.org/problem/P1081

#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
const int N = 100005;
const int INF = 0x3f3f3f3e;

int n, m, s, h[N], des[N][2], Min[N][2], To[N][22], dis[N][22][2], tot[2], x;
struct info {
  int h, id;
  bool operator<(const info& a) const { return h < a.h; };
};
set<info> box;
set<info>::iterator I;
int A(int t) { return t < 0 ? -t : t; }
void consider(int i, info p) {
  int j = p.id;
  if ((A(h[i] - h[j]) < Min[i][0]) ||
      (Min[i][0] == A(h[i] - h[j]) && h[j] < h[des[i][0]])) {
    if ((Min[i][0] < Min[i][1]) ||
        (Min[i][1] == Min[i][0] && h[des[i][0]] < h[des[i][1]]))
      Min[i][1] = Min[i][0], des[i][1] = des[i][0];
    Min[i][0] = A(h[i] - h[j]), des[i][0] = j;
  } else if ((A(h[i] - h[j]) < Min[i][1]) ||
             (Min[i][1] == A(h[i] - h[j]) && h[j] < h[des[i][0]]))
    Min[i][1] = A(h[i] - h[j]), des[i][1] = j;
}
void doubling(int i, int val) {
  for (int k = 20; k >= 0; k--)
    if (dis[i][k][0] + dis[i][k][1] <= val && To[i][k])
      val -= (dis[i][k][0] + dis[i][k][1]), tot[1] += dis[i][k][1],
          tot[0] += dis[i][k][0], i = To[i][k];
  if (des[i][1] && Min[i][1] <= val) tot[1] += Min[i][1];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &h[i]);
    Min[i][1] = Min[i][0] = INF;
  }
  for (int i = n; i >= 1; i--) {
    box.insert((info){h[i], i});
    I = box.find((info){h[i], i});
    ++I;
    if (I != box.end()) {
      consider(i, *I);
      ++I;
      if (I != box.end()) {
        consider(i, *I);
      }
      --I;
    }
    --I;
    if (I != box.begin()) {
      --I;
      consider(i, *I);
      if (I != box.begin()) {
        --I;
        consider(i, *I);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    To[i][0] = des[des[i][1]][0];
    dis[i][0][1] = Min[i][1];
    dis[i][0][0] = Min[des[i][1]][0];
  }
  for (int k = 1; k <= 20; k++) {
    for (int i = 1; i <= n; i++) {
      To[i][k] = To[To[i][k - 1]][k - 1];
      dis[i][k][1] = dis[i][k - 1][1] + dis[To[i][k - 1]][k - 1][1];
      dis[i][k][0] = dis[i][k - 1][0] + dis[To[i][k - 1]][k - 1][0];
    }
  }
  scanf("%d", &x);
  double rate = INF;
  int pos = 0;
  h[0] = -INF;
  for (int i = 1; i <= n; i++) {
    tot[0] = tot[1] = 0;
    doubling(i, x);
    double tmp = tot[0] ? 1.0 * tot[1] / tot[0] : INF;
    if (tmp - rate < 1e-6 && tmp - rate > -1e-6 && h[i] > h[pos]) pos = i;
    if (rate - tmp > 1e-6) {
      pos = i;
      rate = tmp;
    }
  }
  printf("%d\n", pos);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &s, &x);
    tot[0] = tot[1] = 0;
    doubling(s, x);
    printf("%d %d\n", tot[1], tot[0]);
  }
  return 0;
}
