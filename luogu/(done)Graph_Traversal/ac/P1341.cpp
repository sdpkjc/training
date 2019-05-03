// P1341 无序字母对
// https://www.luogu.org/problemnew/show/P1341

#include <iostream>
using namespace std;
const int MAX_N = 300;
const int MAX_M = 90000;
int mat[MAX_N][MAX_N];
int match[MAX_N];         // 表示顶点剩余的度
int n;                    // 顶点个数
int stk[MAX_M], top = 0;  // 用数组 stk 来模拟一个栈
void solve(int u) {
  if (match[u] > 0) {
    for (int i = 1; i <= n; ++i) {
      if (mat[u][i]) {
        mat[u][i]--;
        mat[i][u]--;
        solve(i);
      }
    }
  }
  //   cout << (char)u << endl;
  stk[top++] = u;  // 将顶点 u 插入栈中
}
int main() {
  int N;
  cin >> N;
  n = N;
  n = 300;
  for (int i = 0; i < N; i++) {
    char a, b;
    cin >> a >> b;
    // cout << a << b << endl;
    mat[a][b]++;
    // cout << (int)a << " " << (int)b << endl;
    mat[b][a]++;
    match[b]++;
    match[a]++;
  }
  int cnt = 0, h = 0;             //开始找点
  for (int i = 1; i <= 150; i++)  //在找度数为奇数的点
    if (match[i] & 1) {
      cnt++;
      if (!h) h = i;
    }
  if (!h)  //找不到奇点，就是另外找点
    for (int i = 0; i < 150; i++)
      if (match[i]) {
        h = i;
        break;
      }
  if (cnt && cnt != 2) {
    cout << "No Solution";
    return 0;
  }
  solve(h);
  if (top < N + 1) {
    cout << "No Solution";

  } else {
    for (int i = top - 1; i >= 0; i--) {
      cout << (char)stk[i];
    }
    cout << endl;
  }

  return 0;
}
