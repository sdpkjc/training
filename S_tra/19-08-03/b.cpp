#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

string f(int num) {
  if (num == 0) {
    return "0";
  }
  string re = "";
  while (num != 0) {
    int x = num % 16;
    num /= 16;
    if (x < 10) {
      re = char('0' + x) + re;
    } else {
      re = char('a' + x - 10) + re;
    }
  }
  return re;
}

bool cmp(string &a, string &b) {
  if (a.length() == b.length()) {
    return a < b;
  }
  return a.length() < b.length();
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cout << "Case #" << i << ": ";
    string s;
    cin >> s;
    int arr[10] = {0};
    int cnt = 0;
    int lenx = 0;
    for (int i = 0; i < 8; i++) {
      arr[i] = 0;
      int t = 1;
      for (int j = (i + 1) * 16 - 1; j >= (i)*16; j--) {
        arr[i] += (s[j] - '0') * t;
        t *= 2;
      }
      if (arr[i] == 0) {
        cnt++;
      } else {
        if (cnt >= lenx) {
          lenx = cnt;
        }
        cnt = 0;
      }
    }
    if (cnt >= lenx) {
      lenx = cnt;
    }

    vector<int> V;
    cnt = 0;
    for (int i = 0; i < 8; i++) {
      if (arr[i] == 0) {
        cnt++;
      } else {
        if (cnt == lenx) {
          V.push_back(i - cnt);
        }
        cnt = 0;
      }
    }
    if (cnt == lenx) {
      lenx = cnt;
      V.push_back(8 - cnt);
    }
    if (lenx < 2) {
      for (int i = 0; i < 8; i++) {
        if (i != 0) printf(":");
        printf("%x", arr[i]);
      }
    } else {
      vector<string> vans;
      for (int j = 0; j < V.size(); j++) {
        string tmp = "";
        for (int i = 0; i < V[j]; i++) {
          if (i != 0) tmp += ":";
          tmp += f(arr[i]);
        }
        tmp += "::";
        for (int i = V[j] + lenx; i < 8; i++) {
          tmp += f(arr[i]);
          if (i != 7) tmp += ":";
        }
        vans.push_back(tmp);
      }
      sort(vans.begin(), vans.end(), cmp);
      cout << vans[0];
    }
    cout << endl;
  }
  return 0;
}