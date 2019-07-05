#include <string.h>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

int flag[200005];
int cntflag[200005];

int Scan() {  //输入外挂
  int res = 0, flag = 0;
  char ch;
  if ((ch = getchar()) == '-')
    flag = 1;
  else if (ch >= '0' && ch <= '9')
    res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + (ch - '0');
  return flag ? -res : res;
}

void Out(int a) {  //输出外挂
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a >= 10) Out(a / 10);
  putchar(a % 10 + '0');
}

signed main() {
  int q;
  q = Scan();
  while (q--) {
    int n;
    n = Scan();
    for (int i = 0; i <= n; i++) {
      flag[i] = cntflag[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      int tmp;
      tmp = Scan();
      flag[tmp]++;
    }
    for (int i = n; i >= 1; i--) {
      if (flag[i] != 0) cntflag[flag[i]]++;
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
      if (cntflag[i] > 1) {
        cntflag[i - 1] += (cntflag[i] - 1);
        cntflag[i] = 1;
        ans += i;
      } else if (cntflag[i] > 0) {
        ans += i;
      }
    }

    Out(ans);
    putchar('\n');
  }

  return 0;
}