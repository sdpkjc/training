#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int A, B, ans, pw[10], dB = 0;

queue<pair<int, int> > q;

void dfs(int v, int s, int dep, int max_dep, int last) {
  if (dep > dB + 1) return;
  if (dep == max_dep) {
    if (s <= B && last) {
      q.push(make_pair(s, dep));
      if (s >= A) ans++;
    }
    return;
  }
  int bit = v % 10;
  if (bit + last < 10)
    dfs(v / 10, s + (bit + last) * pw[dep], dep + 1, max_dep, bit + last);
  if (last - bit >= 0 && bit != 0)
    dfs(v / 10, s + (last - bit) * pw[dep], dep + 1, max_dep, last - bit);
}

int main() {
  scanf("%d%d", &A, &B);
  if (A <= 7 && 7 <= B) ans++;
  q.push(make_pair(7, 1));
  pw[0] = 1;
  for (int i = 1; i <= 9; i++) {
    pw[i] = pw[i - 1] * 10;
    if (B > pw[i]) dB = i;
  }
  while (!q.empty()) {
    pair<int, int> h = q.front();
    q.pop();
    for (int i = 0; i <= 9; i++) dfs(h.first, i, 1, h.second + 1, i);
    if (h.second <= dB) q.push(make_pair(h.first, h.second + 1));
  }

  printf("%d", ans);
  return 0;
}