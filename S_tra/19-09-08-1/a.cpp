#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 1e5;
int a8[MAX_N];
int a9[MAX_N];
int a1[MAX_N];
int a0[MAX_N];
int a2[MAX_N];
int a10[MAX_N];
int a102[MAX_N];

int last2[MAX_N];
int last02[MAX_N];
int last102[MAX_N];

int main() {
  int len, m;
  cin >> len >> m;
  string str;
  cin >> str;
  str = " " + str;
  for (int i = 1; i <= len; i++) {
    a8[i] = a8[i - 1];
    a9[i] = a9[i - 1];
    a1[i] = a1[i - 1];
    a0[i] = a0[i - 1];
    a2[i] = a2[i - 1];
    if (str[i] == '8') {
      a8[i]++;
    }
    if (str[i] == '9') {
      a9[i]++;
    }
    if (str[i] == '1') {
      a1[i]++;
    }
    if (str[i] == '0') {
      a0[i]++;
    }
    if (str[i] == '2') {
      a2[i]++;
    }
  }
  for (int i = 1; i <= len; i++) {
    a10[i] = a10[i - 1];
    if (str[i] == '0') {
      a10[i] += a1[i];
    }
  }
  for (int i = 1; i <= len; i++) {
    a102[i] = a102[i - 1];
    if (str[i] == '2') {
      a102[i] += a10[i];
    }
  }
  int q = -1;
  for (int i = 1; i <= len; i++) {
    if (str[i] == '2') {
      q = i;
    }
    last2[i] = q;
  }

  for (int i = 1; i <= len; i++) {
    if (str[i] == '0') {
      q = i;
    }
    last2[i] = q;
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    int c8 = a8[r] - a8[l - 1];
    int c9 = a9[r] - a9[l - 1];
    int c102 = a102[r] - a102[l - 1];
    if (c102 == 0) {
      cout << -1;
    } else {
      while () {
      }
    }
  }
  return 0;
}