/**
* Taylor Mendez
* 4883-Programming Techniques
* 09/09/2021
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    ifstream cin("input.txt");

    int A, B;                   // to read in first value in line and the rest of the values
    vector <int> V;             // to put data in
    bool jolly = true;          
    int diff = 0;

    while (cin >> A){

        if (A == 1){
            cout << "Jolly" << endl;
            cin >> A;
        }

        else {
            vector <int> v((A-1), 0);      // to check
            int hits = 0;                  // to check     


            for (int i = 0; i < A; i++){
                cin >> B;
                V.push_back(B);
            }

            for (int i = 0; i < A; i++){

                if (i != (A - 1))               // make sure its not the last element
                    diff = (V[i+1] - V[i]);
            
                // make sure we get absolute value
                if (diff < 0){
                    diff *= -1;
                }

                // make sure in bounds
                if (diff > v.size()){
                    jolly = false;
                    break;
                }
                // check if we already have that number
                else if (v[diff-1] > 0){
                    jolly = false;
                    break;
                }
                else{
                    v[diff-1]++;
                }
            }

            for (int i = 0; i < v.size(); i++){
                if (v[i] == 1){
                    hits++;
                }
            }

            if (hits == v.size()){
                cout << "Jolly" << endl;
            }
            else{
                cout << "Not Jolly" << endl;
            }

            V.clear();
            v.clear();
            hits = 0;
        }
    }
    return 0;
}