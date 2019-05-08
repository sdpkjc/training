// P1540 机器翻译
// https://www.luogu.org/problemnew/show/P1540

#include <cstdio>
#include <map>
#include <queue>
using namespace std;

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  queue<int> Q;
  map<int, bool> M;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    if (!M[t]) {
      ans++;
      if (Q.size() < m) {
        Q.push(t);
        M[t] = true;
      } else {
        int x = Q.front();
        Q.pop();
        M[x] = false;
        Q.push(t);
        M[t] = true;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}

// 水