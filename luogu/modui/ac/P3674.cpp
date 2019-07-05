// P3674 小清新人渣的本愿
// https://www.luogu.org/problemnew/show/P3674

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
using namespace std;

int N, M;
int k;
const int MAX_N = 100007;

int num[MAX_N];

struct node {
  int k, l, r, x, i;
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

bitset<(size_t)MAX_N> flag, flagF;

inline void add(int x) {
  if (cntA[num[x]]++ == 0) {
    flag[num[x]] = 1;
    flagF[N - num[x]] = 1;
  }
}
inline void dec(int x) {
  if (--cntA[num[x]] == 0) {
    flag[num[x]] = 0;
    flagF[N - num[x]] = 0;
  }
}

int main() {
  scanf("%d%d", &N, &M);
  k = sqrt(N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &num[i]);
  }

  for (int i = 1; i <= M; i++) {
    scanf("%d%d%d%d", &nodeArr[i].k, &nodeArr[i].l, &nodeArr[i].r,
          &nodeArr[i].x);
    nodeArr[i].i = i;
  }
  sort(nodeArr + 1, nodeArr + M + 1, cmpQp);
  int l = 1, r = 0;

  for (int i = 1; i <= M; i++) {
    while (l < nodeArr[i].l) dec(l++);
    while (l > nodeArr[i].l) add(--l);
    while (r > nodeArr[i].r) dec(r--);
    while (r < nodeArr[i].r) add(++r);
    int kk = nodeArr[i].k, xx = nodeArr[i].x;
    // printf("%d %d %d %d\n", nodeArr[i].k, nodeArr[i].l, nodeArr[i].r,
    //    nodeArr[i].x);
    nodeArr[i].ans = 0;
    if (kk == 1) {
      if ((flag & (flag << xx)).any()) nodeArr[i].ans = 1;
    } else if (kk == 2) {
      if ((flag & (flagF >> (N - xx))).any()) nodeArr[i].ans = 1;
    } else if (kk == 3) {
      for (int j = 1; j * j <= xx; j++) {
        if (xx % j == 0 && flag[j] && flag[xx / j]) {
          nodeArr[i].ans = 1;
          break;
        }
      }
    }
  }
  sort(nodeArr + 1, nodeArr + M + 1, cmpQn);
  for (int i = 1; i <= M; i++) {
    if (nodeArr[i].ans == 0) {
      printf("bi\n");
    } else {
      printf("hana\n");
    }
  }

  return 0;
}

// bitset + 莫队
// bitset真好用啊！！！
// 3操作：枚举约数
// 1操作：判断是否存在 z - y = x ，flag左移x位与flag做&运算
// 2操作：判断是否存在 z + y = x ，flagF代表的yy代表 N - y，
// N - yy + z = x -> z - yy = x - N，转化为1操作
