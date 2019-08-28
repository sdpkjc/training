#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int MAXN = 1e3 + 5;

struct Point {
  int x;
  int y;
};
Point P[MAXN];
int c[MAXN];

bool cmpx(Point a, Point b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

bool cmpy(Point a, Point b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    int L = 0, R = 0;
    vector<int> tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      tmp.push_back(x * 10001 + y);
    }
    sort(tmp.begin(), tmp.end());
    int tn = tmp.size() / 2 - 1;
    int tnn = tn + 1;
    int tnx = tn / 10001;
    int tny = tn % 10001;
    int tnnx = tnn / 10001;
    int tnny = tnn % 10001;
    cout << tnx << " " << tny << " " << tnnx << " " << tnny << endl;
    if (tnx == tnnx) {
      cout << tnx << " " << 999000000 << " " << tnnx << " " << -999000000
           << endl;
    } else {
      cout << tnx - 1 << " " << 999000000 << " " << tnnx + 1 << " "
           << tny + tnny - 999000000 << endl;
    }
  }
}