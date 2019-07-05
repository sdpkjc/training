#include <string.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
vector<pair<int, pair<int, int> > > ql;

int n, m;
int ans = 0;

bool flag[1005];

void dfs(int s, int w) {
  ans++;
  for (int i = 0; i < ql.size(); i++) {
    if (ql[i].second.first == s) {
      if (flag[ql[i].second.second] && ql[i].first >= w) {
        flag[ql[i].second.second] = false;
        dfs(ql[i].second.second, w);
      }
    }
    if (ql[i].second.second == s) {
      if (flag[ql[i].second.first] && ql[i].first >= w) {
        flag[ql[i].second.first] = false;
        dfs(ql[i].second.first, w);
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, d;
    cin >> u >> v >> d;
    ql.push_back(make_pair(d, make_pair(u, v)));
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int b, r;
      cin >> b >> r;
      ql[b - 1].first = r;
    } else if (t == 2) {
      int s, w;
      cin >> s >> w;
      memset(flag, true, sizeof(flag));
      ans = 0;
      flag[s] = false;
      dfs(s, w);
      cout << ans << endl;
    }
  }

  return 0;
}