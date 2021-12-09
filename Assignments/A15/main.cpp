#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

using namespace std::chrono;

void solve(string nat, string enc){

    // determine column: int(tolower(char)) - 97
    // 
    //         0 1 2 3 4 5 6 7 8 9 ...
    // letter: a b c d e f g h i j k l m n o p
    // count:  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 

    int naturalAlphabet[2][26]; 
    int encodedAlphabet[2][26];

    // initialize all counts to 0
    // and assign letter 
    for (int i = 0; i < 26; i++){
        naturalAlphabet[0][i] = i + 97;
        naturalAlphabet[1][i] = 0;

        encodedAlphabet[0][i] = i + 97;
        encodedAlphabet[1][i] = 0;
    }

    // count for naturalAlphabet and encodedAlphabet
    int length = 0;
    int natLength = nat.length();
    int encLength = enc.length();
    if (natLength > encLength)
        length = natLength;
    else
        length = encLength;

    for (int i = 0; i < length; i++){
        if (i < natLength){
            if ((int(nat[i]) >= 97 && int(nat[i]) <= 122) || (int(nat[i]) >= 65 && int(nat[i]) <= 90)){
            naturalAlphabet[1][int(tolower(nat[i])) - 97]++;
            }
        }
        if (i < encLength){
            if ((int(enc[i]) >= 97 && int(enc[i]) <= 122) || (int(enc[i]) >= 65 && int(enc[i]) <= 90)){
            encodedAlphabet[1][int(tolower(enc[i])) - 97]++;
            }
        }
    }

    // sort naturalAlphabet and encoded
    for (int i = 0; i < 25; i++){
        // Last i elements are already in place
        for (int j = 0; j < 26-i-1; j++){
            if (naturalAlphabet[1][j] < naturalAlphabet[1][j+1]){
                int tempAlph = naturalAlphabet[0][j];
                int tempCount = naturalAlphabet[1][j];

                naturalAlphabet[0][j] = naturalAlphabet[0][j+1];
                naturalAlphabet[1][j] = naturalAlphabet[1][j+1];

                naturalAlphabet[0][j+1] = tempAlph;
                naturalAlphabet[1][j+1] = tempCount;
            }
            if (encodedAlphabet[1][j] < encodedAlphabet[1][j+1]){
                int tempAlph = encodedAlphabet[0][j];
                int tempCount = encodedAlphabet[1][j];

                encodedAlphabet[0][j] = encodedAlphabet[0][j+1];
                encodedAlphabet[1][j] = encodedAlphabet[1][j+1];

                encodedAlphabet[0][j+1] = tempAlph;
                encodedAlphabet[1][j+1] = tempCount;
            }
        }
    }

    // debug
    // for(int i = 0; i < 26; i++){
    //     cout << (char)naturalAlphabet[0][i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < 26; i++){
    //     cout << naturalAlphabet[1][i] << " ";
    // }
    // cout << endl << endl;

    // for(int i = 0; i < 26; i++){
    //     cout << (char)encodedAlphabet[0][i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < 26; i++){
    //     cout << encodedAlphabet[1][i] << " ";
    // }
    // cout << endl << endl;


    // decode string and print
    for (int i = 0; i < enc.length(); i++){
        for(int j = 0; j < 26; j++){
            if (tolower(enc[i]) == encodedAlphabet[0][j]){
                // if the letter in the ecoded string is capitalized
                if (enc[i] >= 65 && enc[i] <= 90){
                    enc[i] = toupper(naturalAlphabet[0][j]);
                    break;
                }
                else{
                    enc[i] = naturalAlphabet[0][j];
                    break;
                }
            }
        }
    }
    cout << enc << endl << endl;
}

int main(){
    ifstream cin("debug.txt");

    string temp;
    string nat = "";
    string enc = "";

    while (getline(cin, temp)){
        if (!temp.empty()){
            nat += temp;
        }
        else
            break;
    }
    while (getline(cin, temp)){
        // get the first line of encoded string
        enc = temp;
        while(getline(cin, temp)){
            enc = enc + "\n" + temp;
        }
    }
    // solve
    solve(nat, enc);
    return 0;
}