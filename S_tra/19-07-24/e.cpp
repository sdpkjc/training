#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;
int N, C, K, ans;
int a[MAXN];
int c[MAXN];
vector<int> vec;

void DFS(int L, int R) {
  if (L > R || R - L + 1 < ans || R - L + 1 <= K) return;
  vec.clear();
  for (int i = 1; i <= C; i++) c[i] = 0;
  for (int i = L; i <= R; i++) {
    c[a[i]]++;
  }
  vec.push_back(L);
  for (int i = L; i <= R; i++) {
    if (c[a[i]] > 0 && c[a[i]] < K) {
      vec.push_back(i);
    }
  }
  vec.push_back(R);
  int n = vec.size();
  //   cout << n << endl;
  if (n > 2) {
    DFS(L, vec[1] - 1);
    for (int i = 1; i < n - 2; i++) {
      DFS(vec[i] + 1, vec[i + 1] - 1);
    }
    DFS(vec[n - 2] + 1, R);
    return;
  }
  ans = max(ans, R - L + 1);
}

int main() {
  while (~scanf("%d%d%d", &N, &C, &K)) {
    ans = 0;
    for (int i = 1; i <= N; i++) {
      scanf("%d", &a[i]);
    }
    DFS(1, N);
    printf("%d\n", ans);
  }
  return 0;
}