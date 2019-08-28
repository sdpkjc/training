#include <cstdio>
#include <queue>
#include <set>
using namespace std;

int arrA[100005];
int arrB[100005];

int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &arrA[i]);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", &arrB[i]);
    }
    int ans = n;
    deque<int> Qa;
    deque<int> Qb;

    for (int i = 1; i <= n; i++) {
      int aa = 0, bb = 0;
      while (!Qa.empty() && Qa.back() > arrA[i]) {
        Qa.pop_back();
        aa++;
      }
      while (!Qb.empty() && Qb.back() > arrB[i]) {
        Qb.pop_back();
        bb++;
      }
      Qa.push_back(arrA[i]);
      Qb.push_back(arrB[i]);

      if (aa != bb) {
        ans = i - 1;
        break;
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}