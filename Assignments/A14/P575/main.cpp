#include <iostream>
#include <fstream>
#include <tgmath.h>

using namespace std;

int main(){
    string skew;

    fstream cin("input.txt");

    while(cin >> skew){
        int total = 0,
            position = skew.length();
        for(int i = 0; i < skew.length(); i++){
            total += ((int)skew[i] - 48) * (pow(2, position) - 1);
            position--;
        }
        if (total > 0)
            cout << total << endl; 
    }
    return 0;
}