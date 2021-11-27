/**
* Taylor Mendez
* 4883-Programming Techniques
* 09/28/2021
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int>s[3];
int RODS = 3;

int moves,
    m;

void display(){
    cout << endl;
    for (int i = 0; i < RODS; i++){
        if (i == 0)
            cout << "A=>";
        if (i == 1)
            cout << "B=>";
        if (i == 2)
            cout << "C=>";

        for (int j = 0; j < s[i].size(); j++){
            if (s[i].size() == 0)
                break;
            if (j == 0)
                cout << "  ";
            cout << " " << s[i][j];
        }
        cout << endl;
    }
}

void towerofHanoi(int n, char from_rod, char to_rod, char aux_rod){
    if (n == 1){
        // cout << "Move disk 1 from rod " << from_rod
        //      << " to rod " << to_rod << endl;

        s[to_rod].push_back(s[from_rod].back());
        s[from_rod].pop_back();
        m++;

        if (m <= moves){
            display();
        }
        if (m > moves){
            return;
        }

        return;
    }
    else{
        towerofHanoi(n - 1, from_rod, aux_rod, to_rod);
        // cout << "Move disk " << n << " from rod " << from_rod
        //      << " to rod " << to_rod << endl;
        s[to_rod].push_back(s[from_rod].back());
        s[from_rod].pop_back();
        m++;
        if (m <= moves){
            display();
        }
        if (m > moves){
            return;
        }
        towerofHanoi(n - 1, aux_rod, to_rod, from_rod);
    }
}

int main() {

    // A = 0
    // B = 1
    // C = 2


    ifstream cin("input.txt");
    int n;      // number of disks

    int problem = 1;

    while (cin >> n >> moves && n != 0){ 
        cout << "Problem #" << problem << endl;
        m = 0;
        // all disks start in 0 rod
        for (int i = n; i > 0; i--){
            s[0].push_back(i);
        }

        // print initial set up
        display();
        towerofHanoi(n, 0, 2, 1);

        for (int i = 0; i < 3; i++)
            s[i].clear();
        
        problem++;
        cout << endl;
    }
    return 0;
}