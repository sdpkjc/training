// P1215 [USACO1.4]母亲的牛奶 Mother's Milk
// https://www.luogu.org/problemnew/show/P1215

#include <iostream>
using namespace std;

int flag[100];
int A, B, C;
int dfsf[30][30][30];
void dfs(int a, int b, int c) {
  if (a == 0) flag[c] = 1;
  dfsf[a][b][c] = 1;
  if (a != 0) {
    int xb = min(a, B - b);
    int xc = min(a, C - c);
    if (!dfsf[a - xb][b + xb][c]) dfs(a - xb, b + xb, c);
    if (!dfsf[a - xc][b][c + xc]) dfs(a - xc, b, c + xc);
  }

  if (b != 0) {
    int xa = min(b, A - a);
    int xc = min(b, C - c);
    if (!dfsf[a + xa][b - xa][c]) dfs(a + xa, b - xa, c);
    if (!dfsf[a][b - xc][c + xc]) dfs(a, b - xc, c + xc);
  }

  if (c != 0) {
    int xa = min(c, A - a);
    int xb = min(c, B - b);
    if (!dfsf[a + xa][b][c - xa]) dfs(a + xa, b, c - xa);
    if (!dfsf[a][b + xb][c - xb]) dfs(a, b + xb, c - xb);
  }
}

int main() {
  cin >> A >> B >> C;
  dfs(0, 0, C);
  int cnt = 0;
  for (int i = 0; i < 30; i++) {
    if (flag[i]) {
      if (cnt != 0) cout << " ";
      cout << i;
      cnt++;
    }
  }
  cout << endl;
  return 0;
}