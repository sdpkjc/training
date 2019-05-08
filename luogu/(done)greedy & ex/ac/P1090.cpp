// P1090 合并果子
// https://www.luogu.org/problemnew/show/P1090

#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  priority_queue<int, vector<int>, greater<int> > Q;
  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    Q.push(tmp);
  }
  int ans = 0;
  while (Q.size() > 1) {
    int a = Q.top();
    Q.pop();
    int b = Q.top();
    Q.pop();
    ans += a;
    ans += b;
    Q.push(a + b);
  }
  printf("%d\n", ans);

  return 0;
}

// Huffman 编码