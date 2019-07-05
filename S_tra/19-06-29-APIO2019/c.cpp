#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define int long long
const int MAX_N = 2010;

struct bin_tree {
  int n;
  int C[MAX_N];
  int lowbit(int x) { return x & (-x); }
  int getsum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
      res += C[x];
    }
    return res;
  }

  void change_add(int x, int c) {
    for (; x <= n; x += lowbit(x)) {
      C[x] += c;
    }
  }
  void change(int x, int c) {
    int pre = getsum(x) - getsum(x - 1);
    for (; x <= n; x += lowbit(x)) {
      C[x] += c - pre;
    }
  }
} arr_bin_tree[MAX_N];
struct bin_treex {
  int n;
  int C[300005];
  int lowbit(int x) { return x & (-x); }
  int getsum(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) {
      res += C[x];
    }
    return res;
  }

  void change_add(int x, int c) {
    for (; x <= n; x += lowbit(x)) {
      C[x] += c;
    }
  }
  void change(int x, int c) {
    int pre = getsum(x) - getsum(x - 1);
    for (; x <= n; x += lowbit(x)) {
      C[x] += c - pre;
    }
  }
} tmp;
vector<pair<char, pair<int, int> > > vx;

int begint[300005];
int lj[300005];
signed main() {
  int n, q;
  cin >> n >> q;

  string zero;
  cin >> zero;

  bool flag = true;
  for (int i = 1; i <= q; i++) {
    string cmd;
    cin >> cmd;
    int a = -1, b = -1;
    cin >> a;
    if (cmd[0] == 'q') {
      cin >> b;
      if (b - a != 1) {
        flag = false;
      }
    }
    vx.push_back(make_pair(cmd[0], make_pair(a, b)));
  }
  if (flag) {
    tmp.n = n + 10;
    for (int i = 0; i < n; i++) {
      begint[i + 1] = -1;
      lj[i + 1] = 0;
      if (zero[i] == '1') {
        begint[i + 1] = 0;
        lj[i + 1] = 0;
        tmp.change(i + (1), 1);
      }
    }
    for (int i = 1; i <= q; i++) {
      char cmdx = vx[i - 1].first;
      if (cmdx == 'q') {
        int a, b;
        a = vx[i - 1].second.first;
        b = vx[i - 1].second.second;
        b--;
        int len = b - a + 1;
        int ans = 0;
        for (int j = 0; j <= i - 1; j++) {
          if (begint[i] != -1) {
            lj[a] += (i - begint[a]);
            begint[a] = i;
          }
        }
        cout << lj[a] << endl;
      } else if (cmdx == 't') {
        int xi;
        xi = vx[i - 1].second.first;

        int ste = tmp.getsum(xi) - tmp.getsum(xi - 1);

        if (ste == 0) {
          tmp.change(xi, 1);
          begint[xi] = i + 1;
        } else if (ste == 1) {
          tmp.change(xi, 0);
          lj[xi] += (i - begint[xi]);
          begint[xi] = -1;
        }
      }
    }
  } else {
    arr_bin_tree[0].n = n + 10;

    for (int i = 0; i < n; i++) {
      if (zero[i] == '1') {
        arr_bin_tree[0].change(i + (1), 1);
      }
    }
    for (int i = 1; i <= q; i++) {
      arr_bin_tree[i] = arr_bin_tree[i - 1];
      char cmdx = vx[i - 1].first;
      if (cmdx == 'q') {
        int a, b;
        a = vx[i - 1].second.first;
        b = vx[i - 1].second.second;
        b--;
        int len = b - a + 1;
        int ans = 0;
        for (int j = 0; j <= i - 1; j++) {
          if (arr_bin_tree[j].getsum(b) - arr_bin_tree[j].getsum(a - 1) ==
              len) {
            ans++;
          }
        }
        cout << ans << endl;
      } else if (cmdx == 't') {
        int xi;
        xi = vx[i - 1].second.first;

        int ste = arr_bin_tree[i].getsum(xi) - arr_bin_tree[i].getsum(xi - 1);

        if (ste == 0) {
          arr_bin_tree[i].change(xi, 1);
        } else if (ste == 1) {
          arr_bin_tree[i].change(xi, 0);
        }
      }
    }
  }

  return 0;
}