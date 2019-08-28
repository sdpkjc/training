#include <memory.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
using namespace std;
int n, m;
string NM[2000];
int dp[1005][1005];
int h[1005];

int lrres, lrans;
int res = 0;
int ans = 0;
void lr() {
  //   int res = 0;
  lrres = 0;
  lrans = 0;
  stack<int> st;
  for (int i = 0; i < m; i++) {
    while (!st.empty() && h[i] <= h[st.top()]) {
      int cur = st.top();
      st.pop();
      int left = st.empty() ? -1 : st.top();
      if ((i - left - 1) * h[cur] >= lrres) {
        lrans = lrres;
        lrres = (i - left - 1) * h[cur];
      } else if ((i - left - 1) * h[cur] > lrans) {
        lrans = (i - left - 1) * h[cur];
      }

      if (lrres >= res) {
        ans = res;
        res = lrres;
      } else if (lrres >= ans) {
        ans = lrres;
      }
      if (lrans >= res) {
        ans = res;
        res = lrans;
      } else if (lrans >= ans) {
        ans = lrans;
      }
    }
    st.push(i);
  }
  //   cout << "lr: " << lrres << " " << lrans << endl;
  while (!st.empty()) {
    int cur = st.top();
    st.pop();
    int left = st.empty() ? -1 : st.top();
    // res = max(res, (m - left - 1) * h[cur]);
    if ((m - left - 1) * h[cur] >= lrres) {
      lrans = lrres;
      lrres = (m - left - 1) * h[cur];
    } else if ((m - left - 1) * h[cur] > lrans) {
      lrans = (m - left - 1) * h[cur];
    }

    if (lrres >= res) {
      ans = res;
      res = lrres;
    } else if (lrres >= ans) {
      ans = lrres;
    }
    if (lrans >= res) {
      ans = res;
      res = lrans;
    } else if (lrans >= ans) {
      ans = lrans;
    }
    }
  //   return res;
}

int mm() {
  memset(h, 0, sizeof(h));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      h[j] = NM[i][j] == '0' ? 0 : h[j] + 1;
    }
    lr();
    // lrres, lrans;
    // if (lrres >= res) {
    //   ans = res;
    //   res = lrres;
    // } else if (lrres >= ans) {
    //   ans = lrres;
    // }

    // if (lrans >= res) {
    //   ans = res;
    //   res = lrans;
    // } else if (lrans >= ans) {
    //   ans = lrans;
    // }
  }
  return ans;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> NM[i];
  }
  int res = 0;
  int ans = 0;
  cout << mm() << endl;
  return 0;
}
