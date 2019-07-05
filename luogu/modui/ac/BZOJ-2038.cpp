// P2709 小B的询问
// https://www.luogu.org/problemnew/show/P2709

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

#define int long long

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int N, M, K;
int k;
const int MAX_N = 5e5 + 7;

int num[MAX_N];

struct node {
  int l, r, i;
  int ansa, ansb;
} nodeArr[MAX_N];
bool cmpQp(node a, node b) {  //询问排序
  if (a.l / k == b.l / k) return a.r < b.r;
  return a.l < b.l;
}

bool cmpQn(node a, node b) {  //询问排序
  return a.i < b.i;
}
int cntA[MAX_N * 2];
int Xnum;
inline void add(int x) {
  Xnum -= (cntA[num[x]] * cntA[num[x]]);
  cntA[num[x]]++;
  Xnum += (cntA[num[x]] * cntA[num[x]]);
}
inline void dec(int x) {
  Xnum -= (cntA[num[x]] * cntA[num[x]]);
  cntA[num[x]]--;
  Xnum += (cntA[num[x]] * cntA[num[x]]);
}

signed main() {
  scanf("%lld%lld", &N, &M);
  k = sqrt(N);
  for (int i = 1; i <= N; i++) {
    scanf("%lld", &num[i]);
  }

  for (int i = 1; i <= M; i++) {
    scanf("%lld%lld", &nodeArr[i].l, &nodeArr[i].r);
    nodeArr[i].i = i;
  }
  sort(nodeArr + 1, nodeArr + M + 1, cmpQp);
  int l = 1, r = 0;
  Xnum = 0;
  for (int i = 1; i <= M; i++) {
    while (l > nodeArr[i].l) add(--l);
    while (l < nodeArr[i].l) dec(l++);
    while (r < nodeArr[i].r) add(++r);
    while (r > nodeArr[i].r) dec(r--);
    int aa = Xnum - (nodeArr[i].r - nodeArr[i].l + 1);
    int bb = (nodeArr[i].r - nodeArr[i].l + 1) * (nodeArr[i].r - nodeArr[i].l);
    if (aa) {
      int g = gcd(aa, bb);
      aa /= g;
      bb /= g;

      nodeArr[i].ansa = aa;
      nodeArr[i].ansb = bb;
    } else {
      nodeArr[i].ansa = 0;
      nodeArr[i].ansb = 1;
    }
  }
  sort(nodeArr + 1, nodeArr + M + 1, cmpQn);
  for (int i = 1; i <= M; i++) {
    printf("%lld/%lld\n", nodeArr[i].ansa, nodeArr[i].ansb);
  }

  return 0;
}

// 组合数学公式，维和区间各种袜子数量的平方和