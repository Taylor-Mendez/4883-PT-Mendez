#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

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
    // cout << "natural" << endl;
    // for(int i = 0; i < 26; i++){
    //     cout << (char)naturalAlphabet[0][i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < 26; i++){
    //     cout << naturalAlphabet[1][i] << " ";
    // }
    // cout << endl << endl;
    // debug
    // cout << "encoded" << endl;
    // for(int i = 0; i < 26; i++){
    //     cout << (char)encodedAlphabet[0][i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < 26; i++){
    //     cout << encodedAlphabet[1][i] << " ";
    // }
    // cout << endl << endl;

    // new idea making count equal to new index
    for(int i = 0; i < 26; i++){
        encodedAlphabet[1][i] = i;
    }
    for(int i = 0; i < 25; i++){
        for (int j = 0; j < 26-i-1; j++){
            if (encodedAlphabet[0][j] > encodedAlphabet[0][j+1]){
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
    // cout << "encoded after" << endl;
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
        // if its a letter
        if((enc[i] >= 65 && enc[i] <= 90) || (enc[i] >= 97 && enc[i] <= 122)){
            // if its upper case
            if (enc[i] >= 65 && enc[i] <= 90){
                int ind = ((int)tolower(enc[i])) - 97;
                ind = encodedAlphabet[1][ind];
                //cout << ind << " ";
                //cout << (char)toupper(naturalAlphabet[0][ind]) << " ";
                enc[i] = (char)toupper(naturalAlphabet[0][ind]);
            }
            else{
                int ind = (int)enc[i] - 97;
                ind = encodedAlphabet[1][ind];
                //cout << ind << " ";
                //cout << (char)naturalAlphabet[0][ind] << " ";
                enc[i] = (char)naturalAlphabet[0][ind];
            }
        }
    }
    cout << enc << endl << endl;
}

int main(){

    ifstream cin("input2.txt");

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