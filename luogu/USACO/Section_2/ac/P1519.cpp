// P1519 穿越栅栏 Overfencing
// https://www.luogu.org/problem/P1519

#include <string.h>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int M[400][400];
int dist[400][400];
int xans = 0x3f3f3f3f;
vector<pair<int, int> > V;
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};

void bfs(int i, int j) {
  int ans = 0;
  queue<pair<int, pair<int, int> > > Q;
  Q.push(make_pair(0, make_pair(i, j)));
  int flag[400][400];
  for (int i = 0; i <= m * 2; i++)
    for (int j = 0; j <= n * 2; j++) flag[i][j] = M[i][j];

  while (!Q.empty()) {
    int st = Q.front().first;
    int x = Q.front().second.first;
    int y = Q.front().second.second;
    Q.pop();

    dist[x][y] = min(dist[x][y], st);

    for (int i = 0; i < 4; i++) {
      int xxx = x + dirx[i];
      int yyy = y + diry[i];
      int xx = x + dirx[i] * 2;
      int yy = y + diry[i] * 2;
      if (st != 0) {
        if (xx >= 0 && yy >= 0 && flag[xx][yy] == 1 && M[xxx][yyy] == 1) {
          flag[xx][yy] = 0;
          Q.push(make_pair(st + 1, make_pair(xx, yy)));
        }
      }
      if (st == 0) {
        xx = x + dirx[i];
        yy = y + diry[i];
        if (xx >= 0 && yy >= 0 && flag[xx][yy] == 1) {
          flag[xx][yy] = 0;
          Q.push(make_pair(st + 1, make_pair(xx, yy)));
        }
      }
    }
  }
  // xans = min(xans, ans);
}

int main() {
  memset(dist, 0x3f, sizeof(dist));
  cin >> n >> m;
  string s;
  getline(cin, s);
  for (int i = 0; i < m * 2 + 1; i++) {
    getline(cin, s);
    for (int j = 0; j < n * 2 + 1; j++) {
      int ii = i;
      int jj = j;
      char x = s[j];
      if (x == ' ') {
        M[ii][jj] = 1;
      } else {
        M[ii][jj] = 0;
      }
    }
  }

  for (int i = 0; i <= m * 2; i++) {
    for (int j = 0; j <= n * 2; j++) {
      int ii = i;
      int jj = j;
      if (M[ii][jj] == 1 &&
          (ii == 0 || jj == 0 || ii == m * 2 || jj == n * 2)) {
        M[ii][jj] = -1;
      }
    }
  }

  for (int i = 0; i <= m * 2; i++) {
    for (int j = 0; j <= n * 2; j++) {
      int ii = i;
      int jj = j;
      if (M[ii][jj] == -1 &&
          (ii == 0 || jj == 0 || ii == m * 2 || jj == n * 2)) {
        bfs(ii, jj);
      }
    }
  }
  xans = 0;
  for (int i = 0; i <= m * 2; i++) {
    for (int j = 0; j <= n * 2; j++) {
      if (dist[i][j] != 0x3f3f3f3f) {
        xans = max(dist[i][j], xans);
      }
    }
  }
  cout << xans << endl;
  return 0;
}