// P1518 两只塔姆沃斯牛 The Tamworth Two
// https://www.luogu.org/problem/P1518

#include <iostream>
#include <queue>
using namespace std;

int sx, sy;
int ex, ey;
int arr[20][20];
int flag[20][20][20][20][10][10];
int ans = 0x3f3f3f3f;
// 1 -1 2 -2
// b  n d  x
int dirx[4] = {0, 1, 0, -1};
int diry[4] = {-1, 0, 1, 0};

int bfs() {
  queue<
      pair<pair<int, pair<int, int> >, pair<pair<int, int>, pair<int, int> > > >
      Q;
  Q.push(make_pair(make_pair(0, make_pair(0, 0)),
                   make_pair(make_pair(sx, sy), make_pair(ex, ey))));
  while (!Q.empty()) {
    int ti = Q.front().first.first;
    int fx = Q.front().first.second.first;
    int nfx = Q.front().first.second.second;
    int x = Q.front().second.first.first;
    int y = Q.front().second.first.second;
    int nx = Q.front().second.second.first;
    int ny = Q.front().second.second.second;
    Q.pop();
    if (x > 10 || y > 10 || x < 1 || y < 1 || nx > 10 || ny > 10 || nx < 1 ||
        ny < 1)
      continue;
    if (x == nx && y == ny) return ti;
    if (arr[nx + dirx[nfx]][ny + diry[nfx]]) {
      nx += dirx[nfx];
      ny += diry[nfx];
    } else {
      nfx = (nfx + 1) % 4;
    }
    if (arr[x + dirx[fx]][y + diry[fx]]) {
      x += dirx[fx];
      y += diry[fx];
    } else {
      fx = (fx + 1) % 4;
    }
    ti++;
    if (!flag[x][y][nx][ny][fx][nfx]) {
      Q.push(make_pair(make_pair(ti, make_pair(fx, nfx)),
                       make_pair(make_pair(x, y), make_pair(nx, ny))));
      flag[x][y][nx][ny][fx][nfx] = 1;
    }
  }
  return 0;
}

int main() {
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      char t;
      cin >> t;
      arr[j][i] = 1;
      if (t == '*') {
        arr[j][i] = 0;
      } else if (t == '.') {
      } else if (t == 'C') {
        ex = j;
        ey = i;
      } else if (t == 'F') {
        sx = j;
        sy = i;
      }
    }
  }
  cout << bfs() << endl;

  return 0;
}