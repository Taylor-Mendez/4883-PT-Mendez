/**
* Taylor Mendez
* 4883-Programming Techniques
* 09/07/2021
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>


using namespace std;

/*
* function to check if signals are all green at a given second
*
*   visualization for a signal of 11
*   --------------------------------
*   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
*   g g g g g g o o o o  o   r r   r  r  r  r  r  r  r  r  r  g
*
*/
bool checkGreen(vector<int> &v, int time){
	bool result = false;
	int numGreen= 0;    			// to keep track amount of lights that are green at a particular second

	// check for each signal
	for(int i = 0; i < v.size(); i++){
		
		if(time % (v[i]*2) < (v[i] - 5)){
			numGreen++;
			
		}
	}

	// if all lights are green
	if(numGreen == v.size()) 
		result = true;

	return result;
}

int main() {

	//read everything in
	vector<int> V;

	int numOfSets = 0;

	//ifstream cin ("input3.txt");
	int A;
	bool flag1 = true;

	while (flag1){

		cin >> A;
		//  check if its the first number (bc in that case dont need to check if previous was a zero)
		if (V.size() == 0){
			V.push_back(A);
		}
		// vector is not empty
		else{
			if (V.back() != 0){
				V.push_back(A);
			}
			else if (V.back() == 0){
				if (A == 0){
					flag1 = false;
				}
				else {
					V.push_back(A);
				}
			}
		}
	}

	// feel like there is a better way to do this but it'll work for now
	vector <int> v;
	int time = 0;				// time in seconds
	bool allGreen = false;         // for main loop
	for  (int i = 0; i < V.size(); i++){

		if (V[i] != 0){
			v.push_back(V[i]);
		}
		else{
			// do some operations on vector and clear after done

			// check green at every second until 18000 seconds unless synchronization is found
			// start time after minimum signal finishes one cycle
			for (int i = (*min_element(v.begin(), v.end()) + 1); i <= 18000; i++){
				allGreen = checkGreen(v, i);

				if (allGreen == true){
					time = i;
					break;
				}
			}
			if (allGreen == true){
				int hour = time / 3600;
				int second = time % 3600;
				int minute = second / 60;
				second %= 60;

    			cout << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute << ":" 
         		<< setfill('0') << setw(2) << second << endl;
			}
			else{
				cout << "Signals fail to synchronise in 5 hours" << endl;
			}

			v.clear();
			time = 0;
		}
	}
	return 0;
}