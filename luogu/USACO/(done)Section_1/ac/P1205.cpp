// P1205 [USACO1.2]方块转换 Transformations
// https://www.luogu.org/problemnew/show/P1205

#include <iostream>
using namespace std;

int n;
int Mx[20][20];
int My[20][20];
int Ms[20][20];
int Me[20][20];

int Mf[20][20];
int M90[20][20];
int M180[20][20];
int M270[20][20];

void tr90() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      My[i][j] = Mx[n - j - 1][i];
    }
  }
}

void fz() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      My[i][j] = Mx[i][n - j - 1];
    }
  }
}

void cp(int arrA[20][20], int arrB[20][20]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arrA[i][j] = arrB[i][j];
    }
  }
}
bool eq(int arrA[20][20], int arrB[20][20]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arrA[i][j] != arrB[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char tmp;
      cin >> tmp;
      if (tmp == '@') {
        Ms[i][j] = 1;
      } else {
        Ms[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char tmp;
      cin >> tmp;
      if (tmp == '@') {
        Me[i][j] = 1;
      } else {
        Me[i][j] = 0;
      }
    }
  }
  // 1
  cp(Mx, Ms);
  tr90();
  cp(M90, My);
  cp(Mx, My);
  tr90();
  cp(M180, My);
  cp(Mx, My);
  tr90();
  cp(M270, My);

  if (eq(M90, Me)) {
    cout << 1;
  } else if (eq(M180, Me)) {
    cout << 2;
  } else if (eq(M270, Me)) {
    cout << 3;
  } else {
    cp(Mx, Ms);
    fz();
    cp(Mf, My);

    cp(Mx, Mf);
    tr90();
    cp(M90, My);
    cp(Mx, My);
    tr90();
    cp(M180, My);
    cp(Mx, My);
    tr90();
    cp(M270, My);
    if (eq(Mf, Me)) {
      cout << 4;
    } else if (eq(M90, Me) || eq(M180, Me) || eq(M270, Me)) {
      cout << 5;
    } else if (eq(Ms, Me)) {
      cout << 6;
    } else {
      cout << 7;
    }
  }
  cout << endl;

  return 0;
}