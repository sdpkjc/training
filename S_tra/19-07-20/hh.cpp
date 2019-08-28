#include <memory.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
using namespace std;

string NM[2000];
const long long MODA = 1000079;
const long long MODB = 4951;
const long long MODC = 103;
const long long PR = 99997867;
int xxFLAG[MODA];
int xFLAG[MODB];
int AFLAG[MODA];
int BFLAG[MODB];
int CFLAG[MODC];

int dp[1005][1005];
map<pair<int, pair<int, int> >, int> M;
int h[1005];

vector<vector<char> > matrix;

long long hashA(long long a, long long b, long long c) {
  return (a + MODA + PR) % MODA * (b + MODA + PR) % MODA * (c + MODA + PR) %
         MODA * 1990728ll % MODA;
}
long long hashB(long long a, long long b, long long c) {
  return (a + MODB + PR) % MODB * (b + MODB + PR) % MODB * (c + MODB + PR) %
         MODB * 1990728ll % MODB;
}
long long hashC(long long a, long long b, long long c) {
  return (a + MODC + PR) % MODC * (b + MODC + PR) % MODC * (c + MODC + PR) %
         MODC * 1990728ll % MODC;
}
void Af(long long a, long long b, long long c) { AFLAG[hashA(a, b, c)] = 1; }
void Bf(long long a, long long b, long long c) { BFLAG[hashB(a, b, c)] = 1; }
void Cf(long long a, long long b, long long c) { BFLAG[hashB(a, b, c)] = 1; }
bool AB(long long a, long long b, long long c) {
  return AFLAG[hashA(a, b, c)] == 0 || BFLAG[hashB(a, b, c)] == 0 ||
         CFLAG[hashC(a, b, c)] == 0;
}

int maximalRectangle() {
  int ans = 0;
  if (matrix.empty() || matrix[0].empty()) return 0;
  int res = 0, m = matrix.size(), n = matrix[0].size();
  vector<int> height(n, 0), left(n, 0), right(n, n);
  for (int i = 0; i < m; ++i) {
    int cur_left = 0, cur_right = n;
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == '1') {
        ++height[j];
        // left[j] = max(left[j], cur_left);
        if (cur_left >= left[j]) {
          left[j] = cur_left;
        }
      } else {
        height[j] = 0;
        left[j] = 0;
        cur_left = j + 1;
      }
    }
    for (int j = n - 1; j >= 0; --j) {
      if (matrix[i][j] == '1') {
        right[j] = min(right[j], cur_right);
        if (cur_right <= right[j]) {
          right[j] = cur_right;
        }
      } else {
        right[j] = n;
        cur_right = j;
      }

      //   cout << (right[j] - left[j]) * height[j] << endl;
      //   cout << (right[j] - 1 - left[j]) * height[j] << endl;
      //   cout << (right[j] - 1 - left[j]) * (height[j] - 1) << endl;
      //   cout << (right[j] - left[j]) * (height[j] - 1) << endl;

      if (AB(right[j], left[j], height[j])) {
        if ((right[j] - left[j]) * height[j] >= res) {
          ans = res;
          res = (right[j] - left[j]) * height[j];
        } else if ((right[j] - left[j]) * height[j] > ans) {
          ans = (right[j] - left[j]) * height[j];
        }
        Af(right[j], left[j], height[j]);
        Bf(right[j], left[j], height[j]);
      }

      if (AB(right[j] - 1, left[j], height[j])) {
        if ((right[j] - 1 - left[j]) * height[j] >= res) {
          ans = res;
          res = (right[j] - 1 - left[j]) * height[j];
        } else if ((right[j] - 1 - left[j]) * height[j] > ans) {
          ans = (right[j] - 1 - left[j]) * height[j];
        }
        Af(right[j] - 1, left[j], height[j]);
        Bf(right[j] - 1, left[j], height[j]);
      }
      if (AB(right[j], left[j], height[j] - 1)) {
        if ((right[j] - left[j]) * (height[j] - 1) >= res) {
          ans = res;
          res = (right[j] - left[j]) * (height[j] - 1);
        } else if ((right[j] - left[j]) * (height[j] - 1) > ans) {
          ans = (right[j] - left[j]) * (height[j] - 1);
          Af(right[j], left[j], height[j] - 1);
          Bf(right[j], left[j], height[j] - 1);
        }

        if (AB(right[j] - 1, left[j], height[j] - 1)) {
          if ((right[j] - left[j] - 1) * (height[j] - 1) >= res) {
            ans = res;
            res = (right[j] - left[j] - 1) * (height[j] - 1);
          } else if ((right[j] - left[j] - 1) * (height[j] - 1) > ans) {
            ans = (right[j] - left[j] - 1) * (height[j] - 1);
          }
          Af(right[j] - 1, left[j], height[j] - 1);
          Bf(right[j] - 1, left[j], height[j] - 1);
        }
      }
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> NM[i];
  }
  for (int i = 0; i < n; i++) {
    vector<char> tmp;
    for (int j = 0; j < m; j++) {
      tmp.push_back(NM[i][j]);
    }
    matrix.push_back(tmp);
  }
  int res = 0;
  int ans = 0;
  cout << maximalRectangle() << endl;

  return 0;
}
