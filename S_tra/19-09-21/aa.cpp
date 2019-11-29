#include <iostream>
using namespace std;


void f(int n){
    int re = 0;
    for( int i = 1; i <= n; i++){
        re += (n/i);
    }
    if(re % 2 == 1){
        cout << "odd";
    }else{
        cout << "even";
    }cout << endl;
}

int main(){
 for( int i = 1; i <= 1000; i++){
     cout << i << " " ;f(i);
 }
    return 0;
}