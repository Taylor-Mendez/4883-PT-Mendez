/**
* Taylor Mendez
* 4883-Programming Techniques
* 08/30/2021
*/
#include <iostream>
#include <fstream>

#define endl "\n"

using namespace std;

int main() {

    long long int B = 0, A = 0;
    long long int diff = 0;

    ifstream cin("input.txt");

    while (cin >> A >> B) {
        diff = A - B;

        if(diff < 0){
            diff = diff * -1;
        }
        cout << diff << endl;
    }

    return 0;
}