// P2709 小B的询问
// https://www.luogu.org/problemnew/show/P2709

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int N, M, K;
int k;
const int MAX_N = 5e5 + 7;

int num[MAX_N];

struct node {
  int l, r, i;
  int ans;
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

int main() {
  scanf("%d%d%d", &N, &M, &K);
  k = sqrt(N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &num[i]);
  }

  for (int i = 1; i <= M; i++) {
    scanf("%d%d", &nodeArr[i].l, &nodeArr[i].r);
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
    nodeArr[i].ans = Xnum;
  }
  sort(nodeArr + 1, nodeArr + M + 1, cmpQn);
  for (int i = 1; i <= M; i++) {
    printf("%d\n", nodeArr[i].ans);
  }

  return 0;
}

// 裸的莫队，分块