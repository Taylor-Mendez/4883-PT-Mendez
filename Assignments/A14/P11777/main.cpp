#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>

using namespace std;

int testGrade(int a, int b, int c){
    int arr[3] = {a,b,c};
    int minIndex;
    int min = INT_MAX;
    int total = 0;

    for(int i = 0; i < 3; i++){
        if(arr[i] < min){
            minIndex = i;
            min = arr[i];
        }
    }
    for(int i = 0; i < 3; i++){
        if(i != minIndex){
            total += arr[i];
        }
    }
    return (total/2); 
}

void display(int n, int finalGrade){
    if (finalGrade >= 90){
        cout << "Case " << n+1 << ": A" << endl;
    }
    else if (finalGrade >= 80 && finalGrade < 90){
        cout << "Case " << n+1 << ": B" << endl;
    }
    else if (finalGrade >= 70 && finalGrade < 80){
        cout << "Case " << n+1 << ": C" << endl;
    }
    else if (finalGrade >= 60 && finalGrade < 70){
        cout << "Case " << n+1 << ": D" << endl;
    }
    else{
        cout << "Case " << n+1 << ": F" << endl;
    }
}

int main(){
    int N;
    int a,
        b,
        c;
    fstream cin("input2.txt");
    cin >> N;

    for(int i = 0; i < N; i++){
        int finalGrade = 0,
            grade;

        for(int j = 0; j < 4; j++){
            cin >> grade;
            finalGrade += grade;
        }

        cin >> a;
        cin >> b;
        cin >> c; 
        
        finalGrade += testGrade(a,b,c);
        display(i, finalGrade);     
    }
    return 0;
}