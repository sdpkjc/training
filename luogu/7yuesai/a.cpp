#include <iostream>
using namespace std;

int ansM[1200][1200];

void dfs(int x, int y, int len) {
  if (len == 0) return;
  for (int i = x; i < x + len / 2; i++) {
    for (int j = y; j < y + len / 2; j++) {
      ansM[i][j] = 0;
    }
  }
  dfs(x + len / 2, y, len / 2);
  dfs(x, y + len / 2, len / 2);
  dfs(x + len / 2, y + len / 2, len / 2);
}

int main() {
  int n;
  cin >> n;
  int len = (1 << n);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      ansM[i][j] = 1;
    }
  }
  dfs(0, 0, len);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (j != 0) cout << " ";
      cout << ansM[i][j];
    }
    cout << endl;
  }
  return 0;
}