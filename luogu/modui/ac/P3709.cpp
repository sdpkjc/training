// P3709 大爷的字符串题
// https://www.luogu.org/problemnew/show/P3709

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
using namespace std;

int N, M, K;
int k;
const int MAX_N = 2e5 + 7;

struct nums {
  int n, i;
  bool operator<(const nums& b) const { return n < b.n; }
} num[MAX_N];
int disc[MAX_N];

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
int TcntA[MAX_N * 2];

int Xnum;

inline void add(int x) {
  TcntA[cntA[disc[x]]]--;
  TcntA[++cntA[disc[x]]]++;
  Xnum = max(Xnum, cntA[disc[x]]);
}
inline void dec(int x) {
  TcntA[cntA[disc[x]]]--;
  if (cntA[disc[x]] == Xnum && TcntA[cntA[disc[x]]] == 0) Xnum--;
  TcntA[--cntA[disc[x]]]++;
}

int main() {
  scanf("%d%d", &N, &M);
  k = sqrt(N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &num[i].n);
    num[i].i = i;
  }
  sort(num + 1, num + 1 + N);
  for (int i = 1, j = 0; i <= N; i++) {
    if (i == 1 || num[i].n != num[i - 1].n) j++;
    disc[num[i].i] = j;
  }

  for (int i = 1; i <= M; i++) {
    scanf("%d%d", &nodeArr[i].l, &nodeArr[i].r);
    nodeArr[i].i = i;
  }
  sort(nodeArr + 1, nodeArr + M + 1, cmpQp);
  int l = 0, r = 0;
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
    printf("%d\n", -nodeArr[i].ans);
  }

  return 0;
}

// 大爷家1e9的字符集。。。
// 离散化 + 莫队
// 大爷的题不太好懂，题意：给你n个数，m次查询再取负数