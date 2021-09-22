/**
* Taylor Mendez
* 4883-Programming Techniques
* 09/20/2021
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

struct Team{
    int points = 0,
        wins = 0,
        losses = 0,
        ties = 0,
        goalsScored = 0,
        goalsAgainst = 0,
        numGames = 0;
    string name;
};

string lower(string name){
    string newname = name;

    transform(newname.begin(), newname.end(), newname.begin(), ::tolower);

    return newname;
}

bool compare(Team a, Team b){
    if (a.points > b.points)
        return 1;
    else if (a.points == b.points){
        if (a.wins > b.wins)
            return 1;
        else if (a.wins == b.wins){
            if (a.goalsScored - a.goalsAgainst > b.goalsScored - b.goalsAgainst)
                return 1;
            else if (a.goalsScored - a.goalsAgainst == b.goalsScored - b.goalsAgainst){
                if (a.goalsScored > b.goalsScored)
                    return 1;
                else if (a.goalsScored == b.goalsScored){
                    if (a.numGames < b.numGames)
                        return 1;
                    else if (a.numGames == b.numGames){
                        if (lower(a.name) < lower(b.name))                //////////////////////////////
                            return 1;
                        else
                            return 0;
                    }
                    else
                        return 0;
                }
                else return 0;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    else 
        return 0;
}

int main() {

    int A;      // number of tournaments

    ifstream cin("input2.txt");

    cin >> A;
    cin.ignore();
    for (int i = 0; i < A; i++){
        string tName;           // tournament name
        int numTeams,           // number of teams in tournament
            numGames;           // number of games played so far

        // get tournament name
        getline(cin, tName);
        // get number of teams playing
        cin >> numTeams;
        cin.ignore();

        struct Team teams[numTeams];        // array of teams

        // read in team names
        for (int j = 0; j < numTeams; j++){
            getline(cin,teams[j].name);
        }

        // get number of games already played
        cin >> numGames;
        cin.ignore();

        // read results
        for (int j = 0; j < numGames; j++){
            Team team1,         // for calculations
                 team2;         // for calculations

            string tempScore;


            // read game data into temporary team place holders
            getline(cin, team1.name, '#');

            getline(cin, tempScore, '@');
            team1.goalsScored = stoi(tempScore);

            getline(cin, tempScore, '#');
            team2.goalsScored = stoi(tempScore);

            getline(cin, team2.name);

            // team updates based on game data
            if (team1.goalsScored > team2.goalsScored){
                (team1.wins)++;
                (team2.losses)++;
                team1.points += 3;
            }
            if (team2.goalsScored > team1.goalsScored){
                (team2.wins)++;
                (team1.losses)++;
                team2.points += 3;
            }
            if (team1.goalsScored == team2.goalsScored){
                team1.points += 1;
                team2.points += 1;

                (team1.ties)++;
                (team2.ties)++;
            }

            team1.goalsAgainst = team2.goalsScored;
            team2.goalsAgainst = team1.goalsScored;

            (team1.numGames)++;
            (team2.numGames)++;

            for (int k = 0; k < numTeams; k++){
                if (teams[k].name == team1.name){
                    // update with team 1 data
                    teams[k].points += team1.points;
                    teams[k].wins += team1.wins;
                    teams[k].goalsScored += team1.goalsScored;
                    teams[k].goalsAgainst += team1.goalsAgainst;
                    teams[k].numGames += team1.numGames;
                    teams[k].losses += team1.losses;
                    teams[k].ties += team1.ties;
                }

                if (teams[k].name == team2.name){
                    // update with team 2 data
                    teams[k].points += team2.points;
                    teams[k].wins += team2.wins;
                    teams[k].goalsScored += team2.goalsScored;
                    teams[k].goalsAgainst += team2.goalsAgainst;
                    teams[k].numGames += team2.numGames;
                    teams[k].losses += team2.losses;
                    teams[k].ties += team2.ties;
                }
            }
            

        }

        // display tournament info
        cout << tName << endl;
        
        // sort by most point
        sort(teams, teams+numTeams, compare);



        for (int j = 0; j < numTeams; j++){
            cout << j + 1 << ") "
                 << teams[j].name << " " 
                 << teams[j].points << "p, "
                 << teams[j].numGames << "g " 
                 << "(" << teams[j].wins << "-" << teams[j].ties << "-" << teams[j].losses << "), "
                 << teams[j].goalsScored - teams[j].goalsAgainst << "gd "
                 << "(" << teams[j].goalsScored << "-" << teams[j].goalsAgainst << ")"
                 << endl;
        }
        cout << endl;
    }

    return 0;
}