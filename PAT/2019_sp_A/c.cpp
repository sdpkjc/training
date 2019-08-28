#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int call[10000], rev[10000];
int MAP[1005][1005];

int fa[1005];
int flag[1005];
int get(int x) {
  while (fa[x] != 0) {
    x = fa[x];
  }
  return x;
}

void meg(int x, int y) {
  int fx = get(x), fy = get(y);
  if (fx != fy) {
    fa[fx] = fy;
  }
}

bool cmp(vector<int> &a, vector<int> &b) {
  return a[0] < b[0];
  if (a.size() >= b.size())
    return true;
  else {
  }
}

int main() {
  int k, n, m;
  cin >> k >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    MAP[a][b] += c;
  }
  vector<int> xy;
  for (int i = 1; i <= n; i++) {
    int c = 0;
    int cr = 0;
    for (int j = 1; j <= n; j++) {
      if (MAP[i][j] != 0 && MAP[i][j] <= 5) {
        c++;
      }
      if (MAP[i][j] != 0 && MAP[i][j] <= 5 && MAP[j][i]) {
        cr++;
      }
    }
    // cout << c << " " << cr << endl;
    if (c > k && 1.0 * cr <= 0.2 * c) {
      //   cout << i << endl;
      xy.push_back(i);
    }
  }
  sort(xy.begin(), xy.end());
  for (int i = 0; i < xy.size(); i++) {
    for (int j = i + 1; j < xy.size(); j++) {
      if (MAP[xy[i]][xy[j]] && MAP[xy[j]][xy[i]]) {
        meg(xy[i], xy[j]);
        // cout << xy[i] << " " << xy[j] << endl;
      }
    }
  }
  vector<vector<int> > V;
  for (int i = 0; i < xy.size(); i++) {
    if (!flag[xy[i]]) {
      vector<int> tmp;
      tmp.push_back(xy[i]);
      for (int j = i + 1; j < xy.size(); j++) {
        if (!flag[xy[j]] && get(xy[i]) == get(xy[j])) {
          tmp.push_back(xy[j]);
          flag[xy[j]] = 1;
        }
      }
      V.push_back(tmp);
      flag[xy[i]] = 1;
    }
  }
  //   sort(V.begin(), V.end(), cmp);
  if (xy.size() == 0) {
    cout << "None" << endl;
  } else {
    for (int i = 0; i < V.size(); i++) {
      for (int j = 0; j < V[i].size(); j++) {
        if (j != 0) cout << " ";
        cout << V[i][j];
      }
      cout << endl;
    }
  }
  //   cout << xy.size() << endl;

  return 0;
}