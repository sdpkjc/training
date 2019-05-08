// P1031 均分纸牌
// https://www.luogu.org/problemnew/show/P1031

#include <cstdio>
using namespace std;

const int MAXN = 200;

int arr[MAXN];

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }
  int avg = sum / n;
  for (int i = 0; i < n; i++) {
    arr[i] -= avg;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0) {
      arr[i + 1] += arr[i];
      cnt++;
    }
  }

  printf("%d\n", cnt);
  return 0;
}

// 只从一个方向传递，考虑负数