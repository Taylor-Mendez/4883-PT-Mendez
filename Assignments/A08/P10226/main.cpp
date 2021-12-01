/**
* Taylor Mendez
* 4883-Programming Techniques
* 09/20/2021
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

int main() {

    int A;
    ifstream cin("input2.txt");

    cin >> A;
    cin.ignore();

    string placeholder;
    getline(cin, placeholder);

    for (int i = 0; i < A; i++){
        map<string, int> treeCounter;
        string input;
        double totalPop = 0;

        while(getline(cin, input) && input !=""){
            totalPop++;
            // if tree not already in map
            if(!(treeCounter.find(input) != treeCounter.end())){
                treeCounter.insert(pair<string,int>(input,1));
            }
            else{
                treeCounter[input]++;
            }
        }

        // debug
        // for(const auto & key : treeCounter){
        //     cout << key.first << " : " << key.second << endl;
        // }

        // vector to sort alphabetically
        vector<pair<string, int>>trees;
        for(const auto & key : treeCounter){
            trees.push_back(make_pair(key.first, key.second));
        }
        sort(trees.begin(), trees.end());

        if (i == (A-1)){
            for(int j = 0; j < trees.size(); j++){
                cout << trees[j].first << " " << fixed << setprecision(4) << (trees[j].second / totalPop) * 100 << endl;
            }
        }
        else{
            for(int j = 0; j < trees.size(); j++){
                cout << trees[j].first << " " << fixed << setprecision(4) << (trees[j].second / totalPop) * 100 << endl;
            }
            cout << endl;
        }
    }
    return 0;
}