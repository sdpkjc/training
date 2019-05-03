// HDU-4578 Transformation
// https://vjudge.net/problem/HDU-4578

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

typedef long long LL;
const double pi = 4.0 * atan(1.0);
const int MAXN = 100005;
const int M = 10007;
//	代表一次方		平方			立方
LL sumx1[MAXN << 2], sumx2[MAXN << 2], sumx3[MAXN << 2];
//	加				乘				替换
// lazy标记
LL add[MAXN << 2], mul[MAXN << 2];

void PushUp(int rt) {
  sumx1[rt] = (sumx1[rt << 1] % M + sumx1[rt << 1 | 1] % M) % M;
  sumx2[rt] = (sumx2[rt << 1] % M + sumx2[rt << 1 | 1] % M) % M;
  sumx3[rt] = (sumx3[rt << 1] % M + sumx3[rt << 1 | 1] % M) % M;
}

void PushDown(int rt, int len) {
  LL x = 1;
  if (mul[rt] != 1) {
    LL c = mul[rt];
    //这里修改add,原理同update函数里的解释
    add[rt << 1] = add[rt << 1] * c % M;
    add[rt << 1 | 1] = add[rt << 1 | 1] * c % M;

    mul[rt << 1] = (mul[rt << 1] % M * mul[rt] % M) % M;
    mul[rt << 1 | 1] = (mul[rt << 1 | 1] % M * mul[rt] % M) % M;
    sumx3[rt << 1] = (sumx3[rt << 1] % M * c % M * c % M * c % M) % M;
    sumx2[rt << 1] = (sumx2[rt << 1] % M * c % M * c % M) % M;
    sumx1[rt << 1] = (sumx1[rt << 1] % M * c % M) % M;
    sumx3[rt << 1 | 1] = (sumx3[rt << 1 | 1] % M * c % M * c % M * c % M) % M;
    sumx2[rt << 1 | 1] = (sumx2[rt << 1 | 1] % M * c % M * c % M) % M;
    sumx1[rt << 1 | 1] = (sumx1[rt << 1 | 1] % M * c % M) % M;
    mul[rt] = 1;
  }
  if (add[rt]) {
    LL c = add[rt] % M;
    add[rt << 1] = (add[rt << 1] + c) % M;
    add[rt << 1 | 1] = (add[rt << 1 | 1] + c) % M;
    sumx3[rt << 1] =
        (sumx3[rt << 1] +
         (3 * c % M * c % M * sumx1[rt << 1] % M + 3 * c * sumx2[rt << 1] % M) %
             M +
         (c % M * c % M * c % M) % M * (len - (len >> 1))) %
        M;
    sumx2[rt << 1] = (sumx2[rt << 1] + 2 * c % M * sumx1[rt << 1] % M +
                      (c % M * c % M) * (len - (len >> 1)) % M) %
                     M;
    sumx1[rt << 1] = (sumx1[rt << 1] + c * (len - (len >> 1)) % M) % M;
    sumx3[rt << 1 | 1] = (sumx3[rt << 1 | 1] +
                          (3 * c % M * c % M * sumx1[rt << 1 | 1] % M +
                           3 * c * sumx2[rt << 1 | 1] % M) +
                          (c * c * c) * (len >> 1)) %
                         M;
    sumx2[rt << 1 | 1] =
        (sumx2[rt << 1 | 1] + (2 * c % M * sumx1[rt << 1 | 1]) +
         (c * c) * (len >> 1) % M) %
        M;
    sumx1[rt << 1 | 1] = (sumx1[rt << 1 | 1] + c * (len >> 1) % M) % M;
    add[rt] = 0;
  }
}

void update(int kind, int L, int R, LL c, int l, int r, int rt) {
  if (L <= l && r <= R) {
    if (kind == 1)  //加法
    {
      //跟平时遇到的累加一样
      add[rt] = (add[rt] + c) % M;  // lazy标记add累加

      sumx3[rt] = (sumx3[rt] +
                   (3 * c % M * c % M * sumx1[rt] % M + 3 * c * sumx2[rt] % M) +
                   c * c % M * c % M * (r - l + 1)) %
                  M;
      sumx2[rt] = (sumx2[rt] + (2 * c % M * sumx1[rt]) +
                   (c * c % M) * (r - l + 1) % M) %
                  M;
      sumx1[rt] = (sumx1[rt] + c * (r - l + 1) % M) % M;
      return;
    }
    if (kind == 2)  //乘法
    {
      //这里是重点，首先因为加法和乘法同时存在，所以两者之间的顺序关系会影响到结果
      //当前是乘法，那么add标记里的值也要乘上该数字，否则我们必须要考虑加法和乘法的顺序，这样会相当复杂
      //比如(x+3)*4
      //先前add[rt]=3,此时我们进行*4，如果单单mul[rt]*=4,那么更新孩子节点时，就会发现不对了，更新成了x*4+3
      //实际上(x+3)*4=4*x+12
      //好吧，我也讲不清楚了
      add[rt] = add[rt] * c % M;
      mul[rt] = (mul[rt] * c) % M;
      sumx3[rt] = (sumx3[rt] * c % M * c % M * c % M) % M;
      sumx2[rt] = (sumx2[rt] * c % M * c % M) % M;
      sumx1[rt] = (sumx1[rt] * c % M) % M;
      return;
    }
  }
  PushDown(rt, r - l + 1);
  int m = (l + r) >> 1;
  if (L <= m) update(kind, L, R, c, lson);
  if (m < R) update(kind, L, R, c, rson);
  PushUp(rt);
}
LL ans;
void query(int L, int R, int kind, int l, int r, int rt) {
  if (L <= l && r <= R) {
    if (kind == 1)
      ans = (ans + sumx1[rt] % M) % M;
    else if (kind == 2)
      ans = (ans + sumx2[rt] % M) % M;
    else if (kind == 3)
      ans = (ans + sumx3[rt] % M) % M;
    return;
  }
  PushDown(rt, r - l + 1);

  int m = (l + r) >> 1;

  if (L <= m) query(L, R, kind, lson);
  if (m < R) query(L, R, kind, rson);
}
int main() {
  int n, m;
  int i, j, k;
  int x, y, z;
  int t;
  while (~scanf("%d%d", &n, &m)) {
    if (n == 0 && m == 0) break;
    memset(add, 0, sizeof(add));
    memset(mul, 1, sizeof(mul));
    memset(sumx1, 0, sizeof(sumx1));
    memset(sumx2, 0, sizeof(sumx2));
    memset(sumx3, 0, sizeof(sumx3));

    while (m--) {
      scanf("%d%d%d%d", &t, &x, &y, &z);
      if (t == 1 || t == 2)
        update(t, x, y, (LL)z, 1, n, 1);
      else if (t == 4) {
        ans = 0;
        query(x, y, z, 1, n, 1);
        ans %= M;
        printf("%lld\n", ans);
      } else if (t == 3) {
        update(2, x, y, (LL)0, 1, n, 1);
        update(1, x, y, (LL)z, 1, n, 1);
      }
    }
  }
  return 0;
}

// 维护和、积、平方和、立方和，好麻烦，平方和立方展开公式