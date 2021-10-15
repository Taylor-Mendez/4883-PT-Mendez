#include <iostream>
#include <fstream>

using namespace std;

long long int solve(int Z){
    long long int a = 0,
                      b = 1,
                      c;
    for(int i = 0; i < Z; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    ifstream cin("input3.txt");
    int Z;
    while (cin >> Z){
        if (Z != 0)
            cout << solve(Z) << endl;
    }
}