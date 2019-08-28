#include <iostream>
using namespace std;

char M[3][3];

int main() {
  int T;
  cin >> T;
  while (T--) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cin >> M[i][j];
      }
    }
    string flag = "ongoing";
    for (int i = 0; i < 3; i++) {
      if (M[i][0] == 'C' && M[i][1] == 'C' && M[i][2] == 'C') flag = "C";
      if (M[0][i] == 'C' && M[1][i] == 'C' && M[2][i] == 'C') flag = "C";

      if (M[i][0] == 'T' && M[i][1] == 'T' && M[i][2] == 'T') flag = "T";
      if (M[0][i] == 'T' && M[1][i] == 'T' && M[2][i] == 'T') flag = "T";

      if (M[i][0] == 'Z' && M[i][1] == 'Z' && M[i][2] == 'Z') flag = "Z";
      if (M[0][i] == 'Z' && M[1][i] == 'Z' && M[2][i] == 'Z') flag = "Z";
    }
    if (M[0][0] == 'C' && M[1][1] == 'C' && M[2][2] == 'C') flag = "C";
    if (M[0][2] == 'C' && M[1][1] == 'C' && M[2][0] == 'C') flag = "C";

    if (M[0][0] == 'T' && M[1][1] == 'T' && M[2][2] == 'T') flag = "T";
    if (M[0][2] == 'T' && M[1][1] == 'T' && M[2][0] == 'T') flag = "T";

    if (M[0][0] == 'Z' && M[1][1] == 'Z' && M[2][2] == 'Z') flag = "Z";
    if (M[0][2] == 'Z' && M[1][1] == 'Z' && M[2][0] == 'Z') flag = "Z";

    cout << flag << endl;
  }
  return 0;
}