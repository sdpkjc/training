#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Per {
  int arr[15], type;
  string name;
  void init() {
    for (int i = 0; i < 15; i++) {
      arr[i] = 0;
    }
    type = 0;
    name = "";
  }
  void typef() {
    if (arr[10] == 1 && arr[11] == 1 && arr[12] == 1 && arr[13] == 1 &&
        arr[1] == 1) {
      type = 8;
      return;
    }
    for (int i = 1; i <= 13 - 4; i++) {
      if (arr[i] == 1 && arr[i + 1] == 1 && arr[i + 2] == 1 &&
          arr[i + 3] == 1 && arr[i + 4] == 1) {
        type = 7;
        return;
      }
    }
    for (int i = 1; i <= 13; i++) {
      if (arr[i] == 4) {
        type = 6;
        return;
      }
    }
    bool f1 = false, f2 = false;
    for (int i = 1; i <= 13; i++) {
      if (arr[i] == 3) {
        f1 = true;
      }
      if (arr[i] == 2) {
        f2 = true;
      }
    }
    if (f1 && f2) {
      type = 5;
      return;
    } else if (f1) {
      type = 4;
      return;
    }
    int cnt = 0;
    for (int i = 1; i <= 13; i++) {
      if (arr[i] == 2) {
        cnt++;
      }
    }
    if (cnt == 2) {
      type = 3;
      return;
    } else if (cnt == 1) {
      type = 2;
      return;
    }
    type = 1;
    return;
  }
  bool operator<(const Per& B) const {
    if (type != B.type) {
      return type > B.type;
    }
    if (type == 1) {
      int sum1 = 0, sum2 = 0;
      for (int i = 1; i <= 13; i++) {
        sum1 += i * arr[i];
        sum2 += i * B.arr[i];
      }
      if (sum1 == sum2) {
        return name < B.name;
      }
      return sum1 > sum2;
    } else if (type == 2) {
      int Af1 = 0, Af2 = 0, Bf1 = 0, Bf2 = 0;
      for (int i = 1; i <= 13; i++) {
        if (arr[i] == 2) Af1 = i;
        if (arr[i] == 1) Af2 += i;
      }
      for (int i = 1; i <= 13; i++) {
        if (B.arr[i] == 2) Bf1 = i;
        if (B.arr[i] == 1) Bf2 += i;
      }
      if (Af1 != Bf1) {
        return Af1 > Bf1;
      } else {
        if (Af2 != Bf2) {
          return Af2 > Bf2;
        } else {
          return name < B.name;
        }
      }
    } else if (type == 3) {
      int Af1 = 0, Af2 = 0, Af3 = 0, Bf1 = 0, Bf2 = 0, Bf3 = 0;
      for (int i = 1; i <= 13; i++) {
        if (arr[i] == 2) {
          if (Af1 == 0)
            Af1 = i;
          else
            Af2 = i;
        }
        if (arr[i] == 1) Af3 = i;
      }
      for (int i = 1; i <= 13; i++) {
        if (B.arr[i] == 2) {
          if (Bf1 == 0)
            Bf1 = i;
          else
            Bf2 = i;
        }
        if (B.arr[i] == 1) Bf3 = i;
      }
      if (Af2 != Bf2) {
        return Af2 > Bf2;
      } else {
        if (Af1 != Bf1) {
          return Af1 > Bf1;
        } else {
          if (Af3 != Bf3) {
            return Af3 > Bf3;
          } else {
            return name < B.name;
          }
        }
      }
    } else if (type == 4) {
      int Af1 = 0, Af2 = 0, Bf1 = 0, Bf2 = 0;
      for (int i = 1; i <= 13; i++) {
        if (arr[i] == 3) Af1 = i;
        if (arr[i] == 1) Af2 += i;
      }
      for (int i = 1; i <= 13; i++) {
        if (B.arr[i] == 3) Bf1 = i;
        if (B.arr[i] == 1) Bf2 += i;
      }
      if (Af1 != Bf1) {
        return Af1 > Bf1;
      } else {
        if (Af2 != Bf2) {
          return Af2 > Bf2;
        } else {
          return name < B.name;
        }
      }
    } else if (type == 5) {
      int Af1 = 0, Af2 = 0, Bf1 = 0, Bf2 = 0;
      for (int i = 1; i <= 13; i++) {
        if (arr[i] == 3) Af1 = i;
        if (arr[i] == 2) Af2 = i;
      }
      for (int i = 1; i <= 13; i++) {
        if (B.arr[i] == 3) Bf1 = i;
        if (B.arr[i] == 2) Bf2 = i;
      }
      if (Af1 != Bf1) {
        return Af1 > Bf1;
      } else {
        if (Af2 != Bf2) {
          return Af2 > Bf2;
        } else {
          return name < B.name;
        }
      }
    } else if (type == 6) {
      int Af1 = 0, Af2 = 0, Bf1 = 0, Bf2 = 0;
      for (int i = 1; i <= 13; i++) {
        if (arr[i] == 4) Af1 = i;
        if (arr[i] == 1) Af2 = i;
      }
      for (int i = 1; i <= 13; i++) {
        if (B.arr[i] == 4) Bf1 = i;
        if (B.arr[i] == 1) Bf2 = i;
      }
      if (Af1 != Bf1) {
        return Af1 > Bf1;
      } else {
        if (Af2 != Bf2) {
          return Af2 > Bf2;
        } else {
          return name < B.name;
        }
      }

    } else if (type == 7) {
      int f1 = 0;
      int f2 = 0;
      for (int i = 1; i <= 13; i++) {
        if (arr[i] == 1) {
          f1 = i;
          break;
        }
      };
      for (int i = 1; i <= 13; i++) {
        if (B.arr[i] == 1) {
          f2 = i;
          break;
        }
      }
      if (f1 == f2) return name < B.name;
      return f1 > f2;
    } else if (type == 8) {
      return name < B.name;
    }
    return true;
  }
} Parr[100005];

int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      Parr[i].init();
      string tmp;
      cin >> Parr[i].name >> tmp;
      for (int j = 0; j < tmp.length(); j++) {
        if (tmp[j] == '1') {
          Parr[i].arr[10]++;
          j++;
        } else if (tmp[j] >= '2' && tmp[j] <= '9') {
          Parr[i].arr[tmp[j] - '0']++;
        } else if (tmp[j] == 'A') {
          Parr[i].arr[1]++;
        } else if (tmp[j] == 'J') {
          Parr[i].arr[11]++;
        } else if (tmp[j] == 'Q') {
          Parr[i].arr[12]++;
        } else if (tmp[j] == 'K') {
          Parr[i].arr[13]++;
        }
        Parr[i].typef();
      }
    }
    sort(Parr, Parr + n);
    for (int i = 0; i < n; i++) {
      cout << Parr[i].name << endl;
    }
  }
  return 0;
}