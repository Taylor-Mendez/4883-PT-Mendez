// C++ program for implementation of Bubble sort
#include <bits/stdc++.h>
using namespace std;

namespace BubbleSort {
    using namespace std;
    void swap(string *xp, string *yp)
    {
        string temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
 
    // A function to implement bubble sort
    void bubbleSort(string arr[], int n)
    {
        int i, j;
        for (i = 0; i < n-1; i++)    
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
    }
 
    /* Function to print an array */
    void printArray(string arr[], int size)
    {
        int i;
        for (i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}
// This code is contributed by rathbhupendra