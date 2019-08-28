#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

int H[100], Z[100];

struct node {
  int x;
  int cl, cr;
  int dep;
} tree[100];
int cnt = 1;

int dfs(int hl, int hr, int zl, int zr, int dep) {
  if (hl > hr) return 0;
  int rootc = cnt++;
  tree[rootc].x = H[hr];
  tree[rootc].dep = dep;
  int root = H[hr];
  int mid;
  for (int i = zl; i <= zr; i++) {
    if (Z[i] == root) {
      mid = i;
    }
  }
  tree[rootc].cl = dfs(hl, hr - (zr - mid) - 1, zl, mid - 1, dep + 1);
  tree[rootc].cr = dfs(hr - (zr - mid), hr - 1, mid + 1, zr, dep + 1);
  return rootc;
}

int main() {
  tree[0].x = 10000000;
  tree[0].cl = 0;
  tree[0].cr = 0;
  tree[0].dep = -1;

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> Z[i];
  }
  dfs(0, N - 1, 0, N - 1, 0);

  bool fullf = true;

  for (int i = 1; i <= cnt; i++) {
    if ((tree[i].cl == 0 && tree[i].cr != 0) ||
        (tree[i].cl != 0 && tree[i].cr == 0)) {
      fullf = false;
    }
  }

  int M;
  cin >> M;
  string s;
  getline(cin, s);
  for (int i = 0; i < M; i++) {
    bool flag = false;
    getline(cin, s);
    if (s.find("root") != s.npos) {
      stringstream ss;
      ss << s;
      int r;
      ss >> r;
      if (r == tree[1].x) {
        flag = true;
      }
    } else if (s.find("siblings") != s.npos) {
      int a, b;
      string tt;
      stringstream ss;
      ss << s;
      ss >> a >> tt >> b;
      for (int i = 1; i <= cnt; i++) {
        if ((tree[tree[i].cl].x == a && tree[tree[i].cr].x == b) ||
            (tree[tree[i].cl].x == b && tree[tree[i].cr].x == a)) {
          flag = true;
          break;
        }
      }
    } else if (s.find("parent") != s.npos) {
      int a, b;
      string tt;
      stringstream ss;
      ss << s;
      ss >> a >> tt >> tt >> tt >> tt >> b;
      for (int i = 1; i <= cnt; i++) {
        if (tree[i].x == a &&
            (tree[tree[i].cl].x == b || tree[tree[i].cr].x == b)) {
          flag = true;
          break;
        }
      }
    } else if (s.find("left") != s.npos) {
      int a, b;
      string tt;
      stringstream ss;
      ss << s;
      ss >> a >> tt >> tt >> tt >> tt >> tt >> b;
      for (int i = 1; i <= cnt; i++) {
        if (tree[i].x == b && tree[tree[i].cl].x == a) {
          flag = true;
          break;
        }
      }
    } else if (s.find("right") != s.npos) {
      int a, b;
      string tt;
      stringstream ss;
      ss << s;
      ss >> a >> tt >> tt >> tt >> tt >> tt >> b;
      for (int i = 1; i <= cnt; i++) {
        if (tree[i].x == b && tree[tree[i].cr].x == a) {
          flag = true;
          break;
        }
      }
    } else if (s.find("level") != s.npos) {
      int a, b;
      string tt;
      stringstream ss;
      ss << s;
      ss >> a >> tt >> b;
      int al, bl;
      for (int i = 1; i <= cnt; i++) {
        if (tree[i].x == a) {
          al = tree[i].dep;
          break;
        }
      }

      for (int i = 1; i <= cnt; i++) {
        if (tree[i].x == b) {
          bl = tree[i].dep;
          break;
        }
      }
      if (al == bl) {
        flag = true;
      }
    } else if (s.find("full") != s.npos) {
      flag = fullf;
    }
    if (flag) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    cout << endl;
  }
  return 0;
}