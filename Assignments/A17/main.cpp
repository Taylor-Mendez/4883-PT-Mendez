#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

bool solve(string str){
    int target,          // target sum
        start;           // where to start algorithm
    string tag = "";     // to get target sum
    vector <int> stack;  // 

    for(int i = 0; i < str.length(); i++){
        if (str[i] != '('){
            tag += str[i];
        }
        else{
            start = i;
            break;
        }
    }    
    target = stoi(tag);
    
    for(int i = start; i < str.length(); i++){
        string temp = "";       // to hold until we can cast as int

        // case 1
        if(str[i] == '(' && str[i+1] != ')'){
            i++;
            while(str[i] != '('){
                temp += str[i];
                i++;
            }
            i--;
            stack.push_back(stoi(temp));
            // cout << "case 1: ";
            // for (int j = 0; j < stack.size(); j++){
            //     cout << stack[j] << " ";
            // }
            // cout << endl;
        }
        // case 2
        else if(str[i] == '(' && str[i+1] == ')' && str[i+2] == '(' && str[i+3] == ')'){
            i += 3;
            // cout << "case 2: " << accumulate(stack.begin(), stack.end(), 0) << endl;
            if (target == accumulate(stack.begin(), stack.end(), 0)){
                return true;
            }
        }
        // case 3
        else if(str[i] == '(' && str[i+1] == ')'){
            i++;
        }
        // case 4
        else if(str[i] == ')'){
            stack.pop_back();
        }
    }
    return false;
}

int main(){
    fstream cin("input2.txt");
    string str = "";

    char c;
    while(cin >> c){
        int openParen = 0,
            closedParen = 0;

        // get the first total
        while(c != '('){
            str += c;
            cin >> c;
        }
        // start the counting process
        if(c == '('){
            openParen++;
            str += c;
            while(openParen != closedParen){
                cin >> c;
                if(c == '('){
                    openParen++;
                    str += c;
                }
                else if (c == ')'){
                    closedParen++;
                    str += c;
                }
                else    
                    str += c;
            }
            // solve here
            if (solve(str) == true){
                cout << "yes" << endl;
            }
            else
                cout << "no" << endl;
            str = "";
        }


    }

    return 0;
}