#include <assert.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX_N = 10100;
int col[4 * MAX_N], fl[MAX_N];
int Scan() {  //输入外挂
  int res = 0, flag = 0;
  char ch;
  if ((ch = getchar()) == '-')
    flag = 1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + (ch - '0');
  return flag ? -res : res;
}

void Out(int a) {  //输出外挂
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a >= 10) Out(a / 10);
  putchar(a % 10 + '0');
}
void down(int p) {
  col[p * 2] = col[p];
  col[p * 2 + 1] = col[p];
  col[p] = -1;
}

void modify(int p, int l, int r, int x, int y, int c) {
  if (x <= l && r <= y) {
    col[p] = c;
    return;
  }
  if (col[p] != -1) down(p);
  int mid = (l + r) / 2;
  if (x <= mid) {
    modify(p * 2, l, mid, x, y, c);
  }
  if (y > mid) {
    modify(p * 2 + 1, mid + 1, r, x, y, c);
  }
}

int ans;
void query(int p, int l, int r) {
  if (col[p] != -1) {
    if (fl[col[p]] != 1) {
      ans++;
      fl[col[p]] = 1;
    }
    return;
  }
  if (l == r) return;
  int mid = (l + r) / 2;
  query(p * 2, l, mid);
  query(p * 2 + 1, mid + 1, r);
}

int ll[MAX_N], rr[MAX_N];
int tmp[MAX_N * 4];
void init() {
  ans = 0;
  memset(fl, 0, sizeof(fl));
  memset(col, -1, sizeof(col));
  memset(ll, 0, sizeof(ll));
  memset(rr, 0, sizeof(rr));
  memset(tmp, 0, sizeof(tmp));
}
int main() {
  int T = Scan();
  while (T--) {
    init();
    int n = Scan();
    assert(n < 10005);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      ll[i] = Scan();
      rr[i] = Scan();
      tmp[cnt++] = ll[i];
      tmp[cnt++] = rr[i];
    }
    // sort(tmp, tmp + cnt);
    // int m = unique(tmp, tmp + cnt) - tmp;
    // map<int, int> mp;
    // for (int i = 0; i < m; ++i) {
    //   mp[tmp[i]] = i + 1;
    // }
    sort(tmp, tmp + cnt);
    int p = unique(tmp, tmp + cnt) - tmp;
    int k = p;
    for (int i = 1; i < k; i++)
      if (tmp[i] - tmp[i - 1] > 1) tmp[p++] = tmp[i - 1] + 1;
    tmp[p++] = 0;
    sort(tmp, tmp + p);
    for (int i = 1; i <= n; i++) {
      modify(1, 1, p, lower_bound(tmp, tmp + p, ll[i]) - tmp,
             lower_bound(tmp, tmp + p, rr[i]) - tmp, i);
    }
    // for (int i = 1; i <= n; i++) {
    //   modify(1, 1, m, mp[ll[i]], mp[rr[i]], i);
    // }
    query(1, 1, p);
    Out(ans);
    putchar('\n');
  }

  return 0;
}