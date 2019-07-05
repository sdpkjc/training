#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int MAX_N = 20005;
#define int long long

int col[4 * MAX_N], flag[4 * MAX_N];
int X[MAX_N * 3];
int l[MAX_N], r[MAX_N];

void down(int p) {
  // if(col[p] != -1){
  col[p * 2] = col[p];
  col[p * 2 + 1] = col[p];
  col[p] = -1;
  // }
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
void query(int l, int r, int rt) {
  if (col[rt] != -1) {
    if (flag[col[rt]] != 1) {
      ans++;
      flag[col[rt]] = 1;
    }
    return;
  }
  if (l == r) return;
  int m = (l + r) >> 1;
  query(l, m, rt << 1);
  query(m + 1, r, rt << 1 | 1);
}

int t;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    memset(flag, 0, sizeof(flag));
    memset(X, 0, sizeof(X));
    memset(col, -1, sizeof(col));

    cin >> t;
    int tot = 0;
    for (int i = 0; i < t; i++) {
      cin >> l[i] >> r[i];
      X[tot++] = l[i];
      X[tot++] = r[i];
    }

    sort(X, X + tot);
    int p = unique(X, X + tot) - X;
    int k = p;
    for (int i = 1; i < k; i++)
      if (X[i] - X[i - 1] > 1) X[p++] = X[i - 1] + 1;
    X[p++] = 0;
    sort(X, X + p);
    for (int i = 0; i < t; i++) {
      modify(1, 1, p, lower_bound(X, X + p, l[i]) - X,
             lower_bound(X, X + p, r[i]) - X, i);
    }
    ans = 0;
    query(1, p, 1);
    cout << ans << endl;
  }

  return 0;
}