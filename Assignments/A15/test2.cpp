#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


// sort based on second value if equal then alphabetical
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    if (a.second > b.second)
        return 1;
    else if (a.second == b.second)
        return (a.first < b.first);
    else
        return 0;
}

int main(void) {

    ifstream cin("debug.txt");

    char c;
    string input;
    string enc = "";
    map<char,int> counter;
    map<char,char> decoded;

    // initalize counting map to 0 for natural string
    for (c = 'a'; c <= 'z'; c+=1) {
        counter[c] = 0;
    }

    // read in natural string and count
    while (getline(cin, input)) {
        if (input == "") {
            break;
        }
        for(int i = 0; i < input.length(); i++) {
            c = tolower(input[i]);
            if (c >= 'a' && c <= 'z') {
                counter[c] += 1;
            }
        }
    }

    // create vector of pairs to stor characters of natural string and count
    vector< pair<int,int> > chars;
    for (c = 'a'; c <= 'z'; c += 1) {
        chars.push_back(make_pair(c, counter[c]));
    }

    // sort vector by count
    sort (chars.begin(), chars.end(), sortbysec);

    // debug
    // cout << "nat count:" << endl;
    // for(int i = 0; i < chars.size(); i++){
    //     cout << (char)chars[i].first << " "<< chars[i].second << endl;
    // }
    // cout << endl;

    // clear counter to start encoded
    counter.clear();

    // initalize counting map to 0 for encoded string
    for (c = 'a'; c <= 'z'; c+=1) {
        counter[c] = 0;
    }


    // read in encoded string and count
    while (getline(cin, input)) {
        enc += (input + "\n");
        for(int i = 0; i < input.length(); i++) {
            c = tolower(input[i]);
            if (c >= 'a' && c <= 'z') {
                counter[c] += 1;
            }
        }
    }

    // create vector of pairs to store characters of encoded string and count
    vector< pair<int,int> > other_chars;
    for (c = 'a'; c <= 'z'; c += 1) {
        other_chars.push_back(make_pair(c, counter[c]));
    }

    // sort vector by count
    sort (other_chars.begin(), other_chars.end(), sortbysec);

    // debug
    // cout << "enc count:" << endl;
    // for(int i = 0; i < other_chars.size(); i++){
    //     cout << (char)other_chars[i].first << " " << other_chars[i].second << endl;
    // }
    // cout << endl;

    // create decode map using both sorted vectors
    for (int i = 0; i < other_chars.size(); i++) {
        decoded[other_chars[i].first] = chars[i].first;
        decoded[toupper(other_chars[i].first)] = toupper(chars[i].first);
    }

    // decode
    for(int i = 0; i < enc.size(); i++) {
        if ((enc[i] >= 'a' && enc[i] <= 'z') || (enc[i] >= 'A' && enc[i] <= 'Z')){
            cout << decoded[enc[i]];
        } 
        else
            cout << enc[i];
    }
    return 0;
}