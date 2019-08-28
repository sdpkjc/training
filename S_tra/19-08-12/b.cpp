#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;

int pre(string a, string b) {
  int re = 0;
  for (int i = 0; i < a.length() && i < b.length(); i++) {
    if (a[i] == b[i]) {
      re++;
    } else {
      break;
    }
  }
  return re;
}

int nex(string a, string b) {
  int re = 0;
  for (int i = a.length() - 1, j = b.length() - 1; i >= 0 && i >= 0; i--, j--) {
    if (a[i] == b[j]) {
      re++;
    } else {
      break;
    }
  }
  return re;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    string a, b, c;
    cin >> a >> b >> c;
    int lena = a.length();
    int lenb = b.length();
    int lenc = c.length();
    for (int i = lena - 1; i >= 0; i--) {
      if (a[i] == '0')
        a.pop_back();
      else
        break;
    }
    for (int i = lenb - 1; i >= 0; i--) {
      if (b[i] == '0')
        b.pop_back();
      else
        break;
    }
    for (int i = lenc - 1; i >= 0; i--) {
      if (c[i] == '0')
        c.pop_back();
      else
        break;
    }
    int zlena = a.length();
    int zlenb = b.length();
    int zlenc = c.length();

    int pac = pre(a, c);
    int pbc = pre(b, c);
    int nac = nex(a, c);
    int nbc = nex(b, c);
    int aa, ab, ac;
    bool flag = false, f = false;
    if (pac == zlena && nbc == zlenb && pac + nbc <= zlenc) {
      aa = lenc - lena;
      ab = (lenc - zlenc) - (lenb - zlenb);
      ac = 0;
      flag = true;
    } else if (nac == zlena && pbc == zlenb && nac + pbc <= zlenc) {
      aa = (lenc - zlenc) - (lena - zlena);
      ab = lenc - lenb;
      ac = 0;
      flag = true;

    } else {
      {
        // b在前
        string ans = "";
        for (int i = zlena - 1; i >= zlena - nac; i--) {
          ans.push_back(a[i]);
        }
        int i, j, jw = 0;
        int cd = 0;
        for (i = zlena - nac - 1, j = zlenb - 1; i >= 0 && j >= 0; i--, j--) {
          int x = a[i] - '0';
          int y = b[j] - '0';
          ans.push_back(((x + y + jw) % 10) + '0');
          jw = ((x + y + jw) / 10);
          cd++;
        }
        while (i >= 0) {
          int x = a[i] - '0';
          ans.push_back((x + jw) % 10 + '0');
          jw = (x + jw) / 10;
          i--;
        }
        while (j >= 0) {
          int x = b[j] - '0';
          ans.push_back((x + jw) % 10 + '0');
          jw = (x + jw) / 10;
          j--;
        }
        if(jw){
        ans.push_back((jw) + '0');
            f = true;
        }
        ans = string(ans.rbegin(), ans.rend());
        int tlen = ans.length();

        for (int i = tlen - 1; i >= 0; i--) {
          if (ans[i] == '0')
            ans.pop_back();
          else
            break;
        }
        if (ans == c) {
          aa = lenc - (zlenb - cd + lena);
          ab = lenc - lenb;
          ac = 0;
          flag = true;
        }
      }
      {
        // a在前

        string ans = "";
        for (int i = zlenb - 1; i >= zlenb - nbc; i--) {
          ans.push_back(b[i]);
        }
        int i, j, jw = 0;
        int cd = 0;
        for (i = zlenb - nbc - 1, j = zlena - 1; i >= 0 && j >= 0; i--, j--) {
          int x = b[i] - '0';
          int y = a[j] - '0';
          ans.push_back(((x + y + jw) % 10) + '0');
          jw = ((x + y + jw) / 10);
          cd++;
        }
        while (i >= 0) {
          int x = b[i] - '0';
          ans.push_back((x + jw) % 10 + '0');
          jw = (x + jw) / 10;
          i--;
        }
        while (j >= 0) {
          int x = a[j] - '0';
          ans.push_back((x + jw) % 10 + '0');
          jw = (x + jw) / 10;
          j--;
        }
        if(jw){

        ans.push_back((jw) + '0');
            f= true;
        }
        ans = string(ans.rbegin(), ans.rend());

        int tlen = ans.length();
        for (int i = tlen - 1; i >= 0; i--) {
          if (ans[i] == '0')
            ans.pop_back();
          else
            break;
        }

        if (ans == c) {
          aa = lenc - lena;
          ab = lenc - (zlena - cd + lenb);
          ac = 0;
          flag = true;
        }
      }
    }

    if (flag) {
      int absx = max(max(abs(aa), abs(ab)), abs(ac));
      aa += absx;
      ab += absx;
      ac += absx;
      if(f) ac++;
      cout << aa << " " << ab << " " << ac << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}