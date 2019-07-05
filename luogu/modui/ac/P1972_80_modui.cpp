// P1972 [SDOI2009]HH的项链
// https://www.luogu.org/problemnew/show/P1972

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

inline int read() {
  char c = getchar();
  int tot = 1;
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    tot = -1;
    c = getchar();
  }
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum * tot;
}
inline void wr(int x) {
  if (x < 0) {
    putchar('-');
    wr(-x);
    return;
  }
  if (x >= 10) wr(x / 10);
  putchar(x % 10 + '0');
}
const int MAX_N = 5e5 + 7;

int num[MAX_N];

struct node {
  int l, r, i;
  int ans;
} nodeArr[MAX_N];
int k;
bool cmpQp(node a, node b) {  //询问排序
  if (a.l / k == b.l / k) return a.r < b.r;
  return a.l < b.l;
}

bool cmpQn(node a, node b) {  //询问排序
  return a.i < b.i;
}
int cntA[MAX_N * 2];
int Xnum;
inline void add(int x) { Xnum += (++cntA[num[x]] == 1); }
inline void dec(int x) { Xnum -= (--cntA[num[x]] == 0); }

int main() {
  int N;
  N = read();
  k = sqrt(N);
  //   scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    // scanf("%d", &num[i]);
    num[i] = read();
  }

  int M;
  M = read();
  //   scanf("%d", &M);

  for (int i = 1; i <= M; i++) {
    nodeArr[i].l = read();
    nodeArr[i].r = read();
    // scanf("%d%d", &nodeArr[i].l, &nodeArr[i].r);
    nodeArr[i].i = i;
  }
  sort(nodeArr + 1, nodeArr + M + 1, cmpQp);
  int l = 0, r = 0;
  Xnum = 0;
  for (int i = 1; i <= M; i++) {
    // printf("%d %d\n", nodeArr[i].l, nodeArr[i].r);
    while (r < nodeArr[i].r) add(++r);
    while (r > nodeArr[i].r) dec(r--);
    while (l > nodeArr[i].l) add(--l);
    while (l < nodeArr[i].l) dec(l++);
    nodeArr[i].ans = Xnum;
  }
  sort(nodeArr + 1, nodeArr + M + 1, cmpQn);
  for (int i = 1; i <= M; i++) {
    // Out(nodeArr[i].ans);
    // putchar('\n');
    wr(nodeArr[i].ans);
    putchar('\n');
    // printf("%d\n", nodeArr[i].ans);
  }

  return 0;
}

// 莫队，但数据强化了，要用树状数组或线段树
// 莫队 80