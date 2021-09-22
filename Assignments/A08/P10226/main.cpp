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

using namespace std;

struct Tree{
    string species;
    double pop = 0;
};

bool compare(Tree a, Tree b){
    if (a.species < b.species)
        return 1;
    else 
        return 0;
}

int main() {

    int A;
    ifstream cin("input3.txt");

    cin >> A;
    cin.ignore();

    string placeholder;
    getline(cin, placeholder);


    

    for (int i = 0; i < A; i++){
        vector<Tree> population;
        Tree temp;
        double totalPop = 0;

        while(getline(cin, temp.species) && (temp.species).length() != 0){
            totalPop++;
            int found = -1;
            if (population.size() == 0){
                (temp.pop)++;
                population.push_back(temp);
            }
            else if (population.size() != 0){
                for (int j = 0; j < population.size(); j++){
                    if (population[j].species == temp.species)
                        found = j;
                }

                if (found == -1){
                    temp.pop = 1;
                    population.push_back(temp);
                }
                if (found != -1){
                    (population[found].pop)++;
                }
            } 
        }

        sort(population.begin(), population.end(), compare);

        for (int j = 0; j < population.size(); j++){
            cout << population[j].species << " " << fixed << setprecision(4) 
                 << (population[j].pop / totalPop) * 100 << endl;
        }
        cout << endl;

        population.clear();
    }
    

    return 0;
}