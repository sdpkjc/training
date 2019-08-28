#include <iostream>
#include <map>
#include <queue>
using namespace std;

int arr[2000] = {0};

int MAP[100][100];

int dirx[8] = {1, 1, -1, -1, 2, -2, 2, -2};
int diry[8] = {2, -2, 2, -2, 1, -1, -1, 1};

void bfs() {
  queue<pair<int, pair<int, int> > > Q;
  map<pair<int, int>, int> M;
  Q.push(make_pair(0, make_pair(0, 0)));
  M[make_pair(0, 0)]++;
  MAP[50][50] = 0;
  while (!Q.empty()) {
    int st = Q.front().first;
    int x = Q.front().second.first;
    int y = Q.front().second.second;
    Q.pop();
    if (st > 9) break;
    arr[st]++;
    MAP[x + 50][y + 50] = st;

    for (int i = 0; i < 8; i++) {
      int xx = x + dirx[i];
      int yy = y + diry[i];
      if (M[make_pair(xx, yy)] == 0) {
        Q.push(make_pair(st + 1, make_pair(xx, yy)));
        M[make_pair(xx, yy)] = 1;
      }
    }
  }
}

int main() {
  bfs();
  int sum = 0;
  for (int i = 0; i < 50; i++) {
    sum += arr[i];
    cout << arr[i] << endl;
  }

  return 0;
}