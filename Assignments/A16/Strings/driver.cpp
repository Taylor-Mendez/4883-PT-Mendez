#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "heapSort.hpp"
#include "quickSort.hpp"
#include "bubbleSort.hpp"

using namespace std;
using namespace std::chrono;

struct sortCompare {
    string*             data;  // array of numbers
    string*             copy;  // copy of array to actually sort
    int                 n;     // size or number of values to sort
    // int                 m;     // max number
    vector< string > sortNames;

    sortCompare() {
        // m = 1073741824;
        loadData("rwordsdescending.dat");
        // sortNames = {"countSort", "heapSort", "quickSort", "radixSort"};
        sortNames = {"heapSort", "quickSort", "bubbleSort"};
    }

    // function to print the array
    void printArray() {
        for (int i = 0; i < n; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void copyArray() {
        copy = new string[n];

        for (int i = 0; i < n; i++) {
            copy[i] = data[i];
        }
    }

    void loadData(string fileName) {
        ifstream fin;
        fin.open(fileName);
        fin >> n;
        data = new string[n];
        for (int i = 0; i < n; i++) {
            fin >> data[i];
        }
    }

    void writeArray(string* data, string name) {
        ofstream fout;
        fout.open(name);
        for (int i = 0; i < n; i++) {
            fout << data[i] << "\n";
        }
        fout.close();
    }

    void callSortMethod(string sortName) {
        cout << "Making copy of data: \n";
        copyArray();

        cout << "Performing " << sortName << "..." << endl;

        auto start = high_resolution_clock::now();

        if (sortName == "heapSort") {
            HeapSort::heapSort(copy, n);
        } else if (sortName == "quickSort") {
            QuickSort::quickSort(copy, 0, n - 1);
        }  else if (sortName == "bubbleSort") {
            BubbleSort::bubbleSort(copy, n);
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast< microseconds >(stop - start);

        cout << "Duration: " << duration.count() << " microSeconds."<<endl;
        cout << "Writing " << sortName << ".out" << endl;
        
        writeArray(copy, sortName + ".out");

        delete[] copy;
    }
};

// Driver code
int main() {
    sortCompare SC;

    for (int i = 0; i < SC.sortNames.size(); i++) {
        SC.callSortMethod(SC.sortNames[i]);
    }

    cout << SC.sortNames[0] << endl;

    return 0;
}