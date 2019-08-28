#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char M[105][105];

char ans[105][105];

int dirx[4000] = {1, -1, 0, 1};
int diry[4000] = {0, 1, 1, -1};
int st[4000] = {1, 1, 1, 1};
int sedirx[4] = {1, 0, -1, 0};
int sediry[4] = {0, 1, 0, -1};

int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> M[i][j];
      }
    }
    int cnt = 1;
    bool flag = true;
    int a = -1, b = 1;
    int add = 1;
    for (int i = 0; i < 4 * n - 5; i++) {
      if (i % 2 == 0) {
        dirx[i] = flag;
        diry[i] = !flag;
        st[i] = 1;
        flag = !flag;
      } else {
        if (cnt == n - 1) {
          flag = !flag;
          add = -1;
        }
        dirx[i] = a;
        diry[i] = b;
        st[i] = cnt;
        int t = a;
        a = b;
        b = t;
        cnt += add;
      }
    }
    string str = "";
    int x = 0, y = 0;
    for (int i = 0; i < 4 * n - 5; i++) {
      for (int j = 0; j < st[i]; j++) {
        str += M[y][x];
        y += diry[i];
        x += dirx[i];
      }
    }
    str += M[n - 1][n - 1];
    // cout << str << endl;
    st[0] = n - 1;
    for (int i = n - 1, j = 1; i >= 1; i--, j += 2) {
      st[j] = i;
      st[j + 1] = i;
    }
    int xx = 0, yy = 0, c = 0;
    for (int i = 0; i < (n - 1) * 2 + 1; i++) {
      for (int j = 0; j < st[i]; j++) {
        ans[yy][xx] = str[c++];
        xx += sedirx[i % 4];
        yy += sediry[i % 4];
      }
    }
    ans[yy][xx] = str[c++];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << ans[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}