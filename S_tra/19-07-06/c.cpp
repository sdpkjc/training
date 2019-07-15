#include <iostream>
#include <string>
using namespace std;
string ans;

void f(int le) {
  for (int i = 0; i < le; i++) {
    ans += " ";
  }
}

int main() {
  freopen("code.in", "r", stdin);
  freopen("code.out", "w", stdout);
  string tmp;
  string tcode;
  while (getline(cin, tmp)) {
    tcode += tmp;
  }

  string code;
  for (int i = 0; i < tcode.length(); i++) {
    if (tcode[i] == ' ' || tcode[i] == '\t' || tcode[i] == '\r' ||
        tcode[i] == '\n') {
    } else {
      code += tcode[i];
    }
  }

  int lev = 0;
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '{') {
      if (ans.length() > 1 && ans[ans.length() - 1] != ' ') {
        ans += " ";
      }
      ans += code[i];
      ans += '\n';
      lev += 4;
      f(lev);
    } else if (code[i] == ';') {
      ans += code[i];
      if (i + 1 < code.length() && code[i + 1] == '}') {
        lev -= 4;
      }
      ans += '\n';
      f(lev);
    } else if (code[i] == ',') {
      ans += code[i];
      ans += ' ';
    } else if (code[i] == '}') {
      ans += code[i];
    } else {
      ans += code[i];
    }
  }
  cout << ans;
  return 0;
}