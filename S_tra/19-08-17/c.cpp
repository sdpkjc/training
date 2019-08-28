#include <limits.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
//#include<Windows.h>

//#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e4 + 10;

struct Loc {
  int x, y, step;
  bool operator<(const Loc k) const {
    if (x == k.x) return y < k.y;
    return x < k.x;
  }
};
set<Loc> s;
int a[50];
int ans[50];
int dir[8][2] = {{-1, -2}, {-2, -1}, {1, 2},  {2, 1},
                 {-1, 2},  {1, -2},  {2, -1}, {-2, 1}};

void bfs(int x, int y) {
  queue<Loc> q;
  Loc p, t;
  p.x = x;
  p.y = y;
  p.step = 0;
  q.push(p);
  s.insert(p);
  while (!q.empty()) {
    t = q.front();

    q.pop();
    a[t.step]++;
    if (t.step > 50) break;
    for (int i = 0; i < 8; ++i) {
      Loc next;
      next.x = t.x + dir[i][0];
      next.y = t.y + dir[i][1];
      next.step = t.step + 1;
      if (s.find(next) == s.end()) {
        q.push(next);
        s.insert(next);
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  bfs(0, 0);
  for (int i = 0; i < 50; ++i)
    for (int j = 0; j <= i; ++j) ans[i] += a[j];
  for (int i = 1; i < 50; ++i) {
    a[i] += a[i - 1];
  }
  // cout << a[i] << ' ';
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << a[n] << endl;
    cout << ans[n] << endl;
  }
  return 0;
}