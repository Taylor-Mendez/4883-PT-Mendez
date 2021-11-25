// p100
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>

using namespace std;

int getMaxCycleLength(int n1,int n2){
    int max = 0;
    if (n2 >= n1){
        for(int i = n1; i <= n2; i++){
            int cycleLength = 1;
            int n = i;
            while(n != 1){
                if (n%2 == 0){
                    n = n/2;
                }
                else{
                    n = 3 * n + 1;
                }
                cycleLength++;
            }
            if (cycleLength > max)
                max = cycleLength;
        }
    }
    if (n1 > n2){
        for(int i = n1; i >= n2; i--){
            int cycleLength = 1;
            int n = i;
            while(n != 1){
                if (n%2 == 0){
                    n = n/2;
                }
                else{
                    n = 3 * n + 1;
                }
                cycleLength++;
            }
            if (cycleLength > max)
                max = cycleLength;
        }
    }

    return max;
}

int main(){
    ifstream cin("input2.txt");
    int n1,
        n2;

    while(cin >> n1){
        cin >> n2;
        cout << n1 << " " << n2 << " "
             << getMaxCycleLength(n1,n2) << endl;
    }

    return 0;
}