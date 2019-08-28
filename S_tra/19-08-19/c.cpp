#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100100;
int C[MAX_N][2];
int n = MAX_N - 20;

int lowbit(int x) { return x & (-x); }
int getsum(int x, int y) {
  int res = 0;
  for (; x; x -= lowbit(x)) {
    res += C[x][y];
  }
  return res;
}

void change(int x, int c, int y) {
  for (; x <= n; x += lowbit(x)) {
    C[x][y] += c;
  }
}

struct P {
  int x, y;
  char c;
};

P Parr[100005];

vector<int> Vy;

int yh(int y) { return lower_bound(Vy.begin(), Vy.end(), y) - Vy.begin() + 1; }

bool cmpx(const P &a, const P &b) { return a.x < b.x; }
bool cmpy(const P &a, const P &b) { return a.y < b.y; }

int main() {
  int T;
  cin >> T;
  while (T--) {
    int nn, m, k;
    cin >> nn >> m >> k;
    Vy.clear();
    for (int i = 0; i <= k + 10; i++) {
      C[i][0] = C[i][1] = 0;
    }
    for (int i = 0; i < k; i++) {
      cin >> Parr[i].x >> Parr[i].y >> Parr[i].c;
      Vy.push_back(Parr[i].y);
    }
    sort(Vy.begin(), Vy.end());
    sort(Parr, Parr + k, cmpx);
    int ans = 0;
    for (int i = 0; i < k; i++) {
      int a = yh(Parr[i].y);
      if (Parr[i].c == 'U') {
        ans += (getsum(k, 0)) - (getsum(a, 0));
      } else if (Parr[i].c == 'D') {
        ans += (getsum(a, 0));
      } else if (Parr[i].c == 'L') {
      } else if (Parr[i].c == 'R') {
        change(a, 1, 0);
      }
    }

    for (int i = k - 1; i >= 0; i--) {
      int a = yh(Parr[i].y);
      if (Parr[i].c == 'U') {
        ans += (getsum(k, 1)) - (getsum(a, 1));
      } else if (Parr[i].c == 'D') {
        ans += (getsum(a, 1));
      } else if (Parr[i].c == 'L') {
        change(a, 1, 1);
      } else if (Parr[i].c == 'R') {
      }
    }
    cout << ans + 1 << endl;
  }
  return 0;
}