// P1789 【Mc生存】插火把
// https://www.luogu.org/problem/P1789

#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  map<pair<int, int>, int> M;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = a - 2; j <= a + 2; j++) {
      if (j >= 1 && j <= n) M[make_pair(j, b)]++;
    }
    for (int j = b - 2; j <= b + 2; j++) {
      if (j >= 1 && j <= n) M[make_pair(a, j)]++;
    }
    if (b + 1 >= 1 && b + 1 <= n) {
      if (a + 1 >= 1 && a + 1 <= n) M[make_pair(a + 1, b + 1)]++;
      if (a - 1 >= 1 && a - 1 <= n) M[make_pair(a - 1, b + 1)]++;
    }
    if (b - 1 >= 1 && b - 1 <= n) {
      if (a + 1 >= 1 && a + 1 <= n) M[make_pair(a + 1, b - 1)]++;
      if (a - 1 >= 1 && a - 1 <= n) M[make_pair(a - 1, b - 1)]++;
    }
  }
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = a - 2; j <= a + 2; j++) {
      for (int k = b - 2; k <= b + 2; k++) {
        if (j >= 1 && j <= n)
          if (k >= 1 && k <= n) M[make_pair(j, k)]++;
      }
    }
  }
  cout << n * n - M.size() << endl;

  return 0;
}